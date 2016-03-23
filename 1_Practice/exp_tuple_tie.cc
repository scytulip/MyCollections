#include <iostream>
#include <string>
#include <tuple>
#include <vector>

std::tuple<std::string, int, double> func_return_tuple() {
  return std::make_tuple("Hello", 2, 3.14159);
}

/* C++ 11 STL */
// 1. std::pair
// 2. std::tuple
// 3. std::tie

int main() {
  std::vector<std::pair<std::string, int>> v = { 
    {"item1", 1}, {"item2", 2}, {"item3", 5}};
  /*
    std::make_pair("alist", 1),
    std::make_pair("blist", 2),
    std::make_pair("clist", 5) };
  */

  for (auto ent : v) {
    std::cout << ent.first << "," << ent.second << std::endl;
  }

  /* Use of std::tuple */
  std::vector<std::tuple<std::string, int, int>> v2 = {
    std::make_tuple("item1", 1, 999), 
    std::make_tuple("item2", 3, 123), 
    std::make_tuple("item3", 4, 888) }; //std::tuple constructors are explicit

  for (auto ent : v2) {
    std::cout << std::get<0>(ent) << ',' << std::get<1>(ent) << ',' << std::get<2>(ent) << std::endl;
  }

  /* std::tie unpack tuple */
  std::string msg;
  int idx;
  double pi;

  std::tie(msg, idx, pi) = func_return_tuple();

  std::cout << msg << " idx=" << idx << " pi=" << pi << std::endl;

  return 0;
}
