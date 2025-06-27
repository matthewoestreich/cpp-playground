#include <iostream>
#include <vector>

int main() {
  std::vector<int> iv;
  iv.reserve(3);
  for (size_t i = 1; i <= 100; ++i) {
    iv.push_back(i);
  }
  iv.reserve(2);
  std::cout << iv[0] << "," << iv[1] << "," << iv[2] << "," << iv[3] << ","
            << iv[4] << "\n";
  return 0;
}