/*

https://www.youtube.com/shorts/g3omP2v7O88

*/
#pragma once

#include <iostream>

class obj {
 public:
  obj() { std::cout << "called default ctor : 1" << "\n"; }

  obj(const obj&) { std::cout << "called copy ctor : 2\n"; }

  void operator=(const obj&) { std::cout << "called = operator : 3\n"; }
};

inline void objStuff() {
  obj a;
  obj b{};
  obj c();
  obj d = a;
  auto e = obj{};
  obj f = {a};
  obj g(a);
  auto h = b;
  obj(i);
}