#include <memory>

/* Can this program able to compile?
 *
 *  Ans: no. To make it using f(std::move(ptr));
 */
auto f(std::unique_ptr<int> ptr) {
  *ptr = 42;
  return ptr;
}

int main() {
  auto ptr = std::make_unique<int>();
  ptr = f(ptr);
}
