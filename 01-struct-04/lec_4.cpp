#include <iostream>

struct order {
  std::string category;
  std::string product_name;
  int cost;
  std::string customer;
};

class asuhasuawugd_order {
 public:
  std::string category;
  std::string product_name;
  unsigned int cost;
  std::string customer;
};

struct Foo {  // для выравнивания размер кратен 4 байтам
  int iiii;
  char c;
};            // sizeof(Foo) == 8

struct Bar {  // для выравнивания размер кратен 1 байту
  char c8[8];
};

struct Test1 {
  char c;
  Foo foo;
};

struct Test2 {
  char c;
  Bar bar;
};

int main() {
//  Foo ex_0{'a', 42};
//
//  Bar ex_1{"word"};
//
//  Test1 ex2{'v', ex_0};
//
//  Test2 ex3{'v', ex_1};
//
//  std::cout << &ex_0 << ' ' << &ex_1 << ' ' << &ex2 << ' ' << &ex3 << std::endl;
//  std::cout << sizeof(Foo) << ' ' << sizeof(Bar) << ' ' << sizeof(ex2) << ' ' << sizeof(ex3) << std::endl;

  union {
    int int_val;
    long long_val;
    float float_val;
  } ex;

  ex.int_val = 42;
  std::cout << ex.int_val << std::endl;
  ex.long_val = 42;
  std::cout << ex.long_val << std::endl;
  ex.float_val = 42.0;
  std::cout << ex.float_val << std::endl;
  std::cout << ex.int_val << std::endl;

  return 0;
}
