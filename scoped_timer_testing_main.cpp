#include <chrono>
#include <thread>

#include "scoped_timer.hpp"

void scoped_timer_test_1() {
  scoped_timer t("test_1");
  std::this_thread::sleep_for(std::chrono::seconds(2) +
                              std::chrono::milliseconds(500));
}

void scoped_timer_test_2() {
  scoped_timer t("test_2");
  std::this_thread::sleep_for(std::chrono::seconds(3) +
                              std::chrono::milliseconds(500));
}

void main_test() {
  scoped_timer x;
  scoped_timer y;
  scoped_timer z;
  scoped_timer_test_1();
  if (true) {
    scoped_timer_test_2();
  }
}

int main() {
  main_test();

  return 0;
}