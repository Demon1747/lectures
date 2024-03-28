#include <iostream>
#include <memory>
#include <vector>

template <class T>
class Number {
 public:
  Number() = default;

  Number(const T& input) {
    field = new T(input);
  }

  Number(T&& input) {
    field = new T(input);
  }


 private:
  int* field;
};

void smart_ptr_example() {
  int* spec_ref_a = nullptr;
  int* spec_ref_b = nullptr;
  std::shared_ptr<int> spec_ref_c = nullptr;

  {
    int* ref_b = new int(42);
    std::unique_ptr<int> ref_a = std::make_unique<int>(17);
    std::shared_ptr<int> ref_c(new int (100));
    std::cout << spec_ref_c.use_count() << std::endl;
    spec_ref_c = ref_c;
    std::cout << spec_ref_c.use_count() << std::endl;
    std::cout << ref_c.use_count() << std::endl;
    *ref_a += 10;
    *ref_b += 20;

    auto sp_ref_d = std::move(ref_a);
    spec_ref_b = ref_b;
  }

  std::cout << spec_ref_c.use_count() << std::endl;
}

template<class T>
void func(T&& arg) {
  Number aaaaaa(std::move(arg));
}

void move_example() {
  int x = 52;
  int y = 123;
  Number a(42);
  Number b(y);
  func(x);
}

int main() {
  smart_ptr_example();
  move_example();
}
