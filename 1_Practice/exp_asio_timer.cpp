#include <asio.hpp>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

// C++11 Experiment
// 1. asio::steady_timer using chrono
// 2. Multi-thread io_service
// 3. std::bind
// 4. Use std::mutex instead of asio::strand

class Printer {
public:
  Printer(asio::io_service& io) :
//      strand_(io),
      timer1_(io, std::chrono::milliseconds(500)),
      timer2_(io, std::chrono::milliseconds(300)),
      ct_(0) {
//    timer1_.async_wait(strand_.wrap(std::bind(&Printer::handler1, this)));
//    timer2_.async_wait(strand_.wrap(std::bind(&Printer::handler2, this)));
    timer1_.async_wait(std::bind(&Printer::handler1, this));
    timer2_.async_wait(std::bind(&Printer::handler2, this));
  }
  ~Printer() = default;

  void handler1() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (ct_ < 10) {
      std::cout << "Handler 1: " << ct_ << std::endl;
      ++ ct_;
      timer1_.expires_at(timer1_.expires_at() + std::chrono::milliseconds(500));
//      timer1_.async_wait(strand_.wrap(std::bind(&Printer::handler1, this)));
      timer1_.async_wait(std::bind(&Printer::handler1, this));
    }
  }
  void handler2() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (ct_ < 10) {
      std::cout << "Handler 2: " << ct_ << std::endl;
      ++ ct_;
      timer2_.expires_at(timer2_.expires_at() + std::chrono::milliseconds(300));
//      timer2_.async_wait(strand_.wrap(std::bind(&Printer::handler2, this)));
      timer2_.async_wait(std::bind(&Printer::handler2, this));
    }
  }
private:
  //asio::io_service::strand strand_;
  asio::steady_timer timer1_;
  asio::steady_timer timer2_;
  mutable std::mutex mutex_;
  int ct_; // Shared resource
};

//void print(const asio::error_code& e,
//           asio::steady_timer& t, int& ct) {
//  if (ct < 5) {
//    std::cout << "Count: " << ct << std::endl;
//    ++ ct;
//
//    t.expires_at(t.expires_at() + std::chrono::seconds(1));
//    // std::bind accepts rvalue. To pass reference, use std::ref explicitly.
//    // http://stackoverflow.com/questions/17432039/stdbind-lose-reference-when-delivered-as-rvalue-reference
//    t.async_wait(std::bind(&print, std::placeholders::_1, std::ref(t), std::ref(ct)));
//  }
//}


int main()
{
  asio::io_service io;

//  int ct = 0;
//  asio::steady_timer t(io, std::chrono::seconds(1));
//  t.async_wait(std::bind(&print, std::placeholders::_1, std::ref(t), std::ref(ct)));
//  io.run();

  Printer p(io);
  std::size_t (asio::io_service::*asio_run)() = &asio::io_service::run;
  std::thread th(asio_run, &io);
  io.run();
  th.join();

  return 0;
}
