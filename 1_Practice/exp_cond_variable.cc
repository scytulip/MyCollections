/* An experimental code for c++ condition variable */

#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>

class TestClsX {
 public:
  TestClsX() : count(0) {}

  void provider(int proc) {
    int value;
    while(true) {
      // Use std::defer_lock to avoid lock during construction.
      { std::unique_lock<std::mutex> lock(count_mut, std::defer_lock);
        lock.lock();
        if (count >= MAX_COUNT){
          lock.unlock();
          break;
        } else {
          value = ++count;
          lock.unlock();
        }
      }
      { std::lock_guard<std::mutex> lk(dataq_mut);
        dataq.push(std::pair<int, int>(proc, value));
        dataq_cond.notify_one();
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(rand()%10));
    }
  }

  void consumer(int proc) {
    while(true) {
      // Must use unique_lock
      std::unique_lock<std::mutex> lk(dataq_mut);
      { std::lock_guard<std::mutex> lock(count_mut);
        if (count == MAX_COUNT && dataq.empty()) {
          lk.unlock();
          return;
        }
      }
      // & is needed, http://stackoverflow.com/questions/4940259/lambdas-require-capturing-this-to-call-static-member-function
      dataq_cond.wait(
          lk, [&]{return !dataq.empty();});  
      std::pair<int, int> i = dataq.front();
      dataq.pop();
      std::cout << "Process " << i.first << " provides #" << i.second << ", consumed by process " << proc << std::endl;
      lk.unlock();
      std::this_thread::sleep_for(std::chrono::milliseconds(rand()%10));
    }
  }

  void make_provider_threads() {
    for (int i=0; i<3; ++i) {
      pthreads.push_back(std::thread(&TestClsX::provider, this, i));
    }
    std::for_each(pthreads.begin(), pthreads.end(), std::mem_fn(&std::thread::join));
  }

  void make_consumer_threads() {
    for (int i=0; i<5; ++i) {
      cthreads.push_back(std::thread(&TestClsX::consumer, this, i));
    }
    std::for_each(cthreads.begin(), cthreads.end(), std::mem_fn(&std::thread::join));
  }


 private:
  mutable std::mutex dataq_mut;
  std::queue<std::pair<int, int>> dataq;
  std::condition_variable dataq_cond;
  mutable std::mutex count_mut;
  int count;
  const int MAX_COUNT = 20;
  std::vector<std::thread> pthreads;
  std::vector<std::thread> cthreads;
};

int main() {
  TestClsX testcls_;

  testcls_.make_provider_threads();
  testcls_.make_consumer_threads();

  return 0;
}
