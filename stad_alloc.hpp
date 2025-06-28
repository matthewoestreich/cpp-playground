/*
Stadium allocator - can use with std::vector<T, stad_alloc<T>>
*/
#include <print>

template <typename T>
struct stad_alloc {
  using value_type = T;

  stad_alloc() {
    std::println("Default stad_alloc<{}>", typeid(T).name());
  }

  template <typename U>
  stad_alloc(const stad_alloc<U>&) {
    std::println("Rebinding stad_alloc from <{}> to <{}>", typeid(U).name(),
                 typeid(T).name());
  }

  T* allocate(std::size_t n) {
    std::println("Allocating {} obbjects of type {}", n, typeid(T).name());
    return static_cast<T*>(operator new(n * sizeof(T)));
  }

  void deallocate(T* p, std::size_t n) {
    std::println("Deallocating {} objects of type {}", n, typeid(T).name());
    operator delete(p);
  }

  template <typename U>
  bool operator==(const stad_alloc<U>&) const noexcept {
    return true;
  }

  template <typename U>
  bool operator!=(const stad_alloc<U>&) const noexcept {
    return false;
  }
};
