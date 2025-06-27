#pragma once

#include <chrono>
#include <print>
#include <random>
#include <string>

class scoped_timer {
 public:
  scoped_timer() { _name = "id:" + std::to_string(getRandInt()); };

  scoped_timer(const std::string& name) : _name(name) {};

  ~scoped_timer() {
    std::chrono::time_point<std::chrono::steady_clock> end_time =
        std::chrono::high_resolution_clock::now();

    auto ns = std::chrono::nanoseconds(end_time.time_since_epoch() -
                                       _start_time.time_since_epoch());

    std::chrono::duration<double> ms =
        std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(
            ns);

    std::chrono::duration<double> secs =
        std::chrono::duration_cast<std::chrono::duration<double>>(ns);

    std::println("\"{}\" took: {:.10f}s", _name, secs.count());
  };

 private:
  int getRandInt() {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, INT_MAX);
    return dist(rng);
  }
  std::string _name;
  std::chrono::time_point<std::chrono::steady_clock> _start_time =
      std::chrono::high_resolution_clock::now();
};