#include <deque>
#include <iostream>
#include <string>

/* C++ STL Test Class */
/* 1. deque operation */
/* 2. copy & move ctors, operator= */

class TestCls {
 public:
  /* Constructors */
  explicit TestCls(const std::string& mark_) : mark(mark_) {
    this_id = ++obj_id;
    std::cout << "Obj(" << this_id << ") with marker \"" << mark 
              << "\" is constructed." << std::endl;
  }
  
  TestCls(const TestCls& test_) { // copy ctor
    this_id = ++obj_id;
    mark = test_.mark;
    std::cout << "Obj(" << this_id << ") is constructed and copies marker \"" << mark
              << "\" from Obj(" << test_.this_id << ")." << std::endl;
  }
  
  TestCls(TestCls&& test_) : 
      mark(std::move(test_.mark)){ // move ctor
    this_id = ++obj_id;
    std::cout << "Obj(" << this_id << ") with marker \"" << mark 
              << "\" is moved from Obj(" << test_.this_id << ")." << std::endl;
  }
  
  /* Operators */
  TestCls& operator=(const TestCls& test_) {
    mark = test_.mark;
    std::cout << "Obj(" << this_id << ") sets marker to \"" << mark
              << "\", copied from Obj(" << test_.this_id << ")." << std::endl;
    return *this;
  }
  
  TestCls& operator=(TestCls&& test_) {
    mark = std::move(test_.mark);
    std::cout << "Obj(" << this_id << ") sets marker to \"" << mark
              << "\", moved from Obj(" << test_.this_id << ")." << std::endl;
    return *this;
  }
  
  /* Destructor */
  ~TestCls() {
    std::cout << "Obj(" << this_id << ") with marker \"" << mark 
              << "\" is destructed." << std::endl;
  }
  
 private:
  std::string mark;
  int this_id;
  static int obj_id;
};

int TestCls::obj_id = 0; // static initialization

int main() {
  std::cout << "...Start..." << std::endl;
  
  std::deque<TestCls> cc = {
    TestCls(std::to_string(1)),
    TestCls(std::to_string(2)), 
    TestCls(std::to_string(3)) };

  for (int i = 0; i<8; ++i) {
    cc.push_back(TestCls(std::to_string(i+4)));
  }

  std::deque<TestCls>::iterator i = cc.begin()+4;
  cc.insert(i, 3, TestCls("extra"));
  
  std::cout << "...End..." << std::endl;

  return 0;
}

/* Output:
...Start...
Obj(1) with marker "1" is constructed.
Obj(2) with marker "2" is constructed.
Obj(3) with marker "3" is constructed.
Obj(4) is constructed and copies marker "1" from Obj(1).
Obj(5) is constructed and copies marker "2" from Obj(2).
Obj(6) is constructed and copies marker "3" from Obj(3).
Obj(3) with marker "3" is destructed.
Obj(2) with marker "2" is destructed.
Obj(1) with marker "1" is destructed.
Obj(7) with marker "4" is constructed.
Obj(8) with marker "4" is moved from Obj(7).
Obj(7) with marker "" is destructed.
Obj(9) with marker "5" is constructed.
Obj(10) with marker "5" is moved from Obj(9).
Obj(9) with marker "" is destructed.
Obj(11) with marker "6" is constructed.
Obj(12) with marker "6" is moved from Obj(11).
Obj(11) with marker "" is destructed.
Obj(13) with marker "7" is constructed.
Obj(14) with marker "7" is moved from Obj(13).
Obj(13) with marker "" is destructed.
Obj(15) with marker "8" is constructed.
Obj(16) with marker "8" is moved from Obj(15).
Obj(15) with marker "" is destructed.
Obj(17) with marker "9" is constructed.
Obj(18) with marker "9" is moved from Obj(17).
Obj(17) with marker "" is destructed.
Obj(19) with marker "10" is constructed.
Obj(20) with marker "10" is moved from Obj(19).
Obj(19) with marker "" is destructed.
Obj(21) with marker "11" is constructed.
Obj(22) with marker "11" is moved from Obj(21).
Obj(21) with marker "" is destructed.
Obj(23) with marker "extra" is constructed.
Obj(24) is constructed and copies marker "extra" from Obj(23).
Obj(25) with marker "1" is moved from Obj(4).
Obj(26) with marker "2" is moved from Obj(5).
Obj(27) with marker "3" is moved from Obj(6).
Obj(4) sets marker to "4", moved from Obj(8).
Obj(5) sets marker to "extra", copied from Obj(24).
Obj(6) sets marker to "extra", copied from Obj(24).
Obj(8) sets marker to "extra", copied from Obj(24).
Obj(24) with marker "extra" is destructed.
Obj(23) with marker "extra" is destructed.
...End...
Obj(25) with marker "1" is destructed.
Obj(26) with marker "2" is destructed.
Obj(27) with marker "3" is destructed.
Obj(4) with marker "4" is destructed.
Obj(5) with marker "extra" is destructed.
Obj(6) with marker "extra" is destructed.
Obj(8) with marker "extra" is destructed.
Obj(10) with marker "5" is destructed.
Obj(12) with marker "6" is destructed.
Obj(14) with marker "7" is destructed.
Obj(16) with marker "8" is destructed.
Obj(18) with marker "9" is destructed.
Obj(20) with marker "10" is destructed.
Obj(22) with marker "11" is destructed.
*/