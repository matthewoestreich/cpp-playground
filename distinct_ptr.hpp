#include <cstdlib>
#include <print>

template <typename T>
class distinct_ptr {
 public:
  distinct_ptr<T>() : _ptr(nullptr) {};

  explicit distinct_ptr<T>(T* ptr) : _ptr(ptr) {};

  distinct_ptr<T>(const distinct_ptr<T>&) = delete;
  distinct_ptr<T> operator=(const distinct_ptr<T>&) = delete;

  distinct_ptr<T>(distinct_ptr<T>&& other) noexcept : _ptr(other._ptr) {
    std::println("[distinct_ptr] called move constructor");
  };

  ~distinct_ptr<T>() { delete _ptr; }

  distinct_ptr<T>& operator=(distinct_ptr<T>&& other) {
    if (this != &other) {
      delete _ptr;
      _ptr = other._ptr;
      other._ptr = nullptr;
    }
    return *this;
  };

  T& operator*() { return *_ptr; };
  const T& operator*() const { return *_ptr; };

  T* operator->() { return _ptr; };
  const T* operator->() const { return _ptr; };

 private:
  T* _ptr;
};