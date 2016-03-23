#include <functional>
#include <iostream>
#include <string>

/* C++ 11 STL */
// 1. constexpr object
// 2. rvalue & lvalue
// 3. Lambda function

class TestCls{
 public:
  TestCls() = default;
  constexpr TestCls(const int& a_) : a(a_) {} // constexpr constructor, only empty body
  constexpr int get_sqr() { return a*a; }
 private:
  int a;
};

void Func(int&& x) {
  std::cout << "rvalue value = " << x << std::endl;
}

void Func(const int& x) {
  std::cout << "lvalue value = " << x << std::endl;
}

int main() {
  int a = 100;
  Func(72); // rvalue parameter
  Func(a);  // lvalue parameter

  // Move string
  std::string c = "Hello!";
  std::string d(std::move(c));
  std::cout << "string c = " << c << std::endl;
  std::cout << "string d = " << d << std::endl;

  // constexpr constructor
  int q[TestCls(3).get_sqr()];
  std::cout << "the size of q is " << sizeof(q) << " bytes"  << std::endl;

  std::cout << std::endl;

  // Inline Lambda
  [] {
    std::cout << "Inline Lambda!" << std::endl;
  }();

  // Lambda function
  std::function<int(int)> fibo = [&](int n)->int{ // return type "->int", capture by reference "&fibo"
      return (n>2) ? fibo(n-1)+fibo(n-2) : 1;     // recursive Lambda
  };
  std::cout << "Fibonacci(10) = " << fibo(10) << std::endl;

  return 0;
}
