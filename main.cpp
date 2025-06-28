#include <vector>

#include "stad_alloc.hpp"

int main() {
  std::vector<int, stad_alloc<int>> v{1};
  for (size_t i = 10; i <= 100; ++i) {
    v.push_back(i);
  }
  return 0;
}