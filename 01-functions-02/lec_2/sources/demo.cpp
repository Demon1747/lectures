#include <iostream>
#include <string>

// Создает копию переменной time с именем input внутри функции
void func1(std::string input) {
  input = "word has been changed";
}

// Делает input псевдонимом time
void func2(std::string &input) {
  input = "word has been changed";
}

// Делает input псевдонимом time, input нельзя изменить
void func3(const std::string &input) {
//  input = "word has been changed";
}

int main() {
  std::string time;
  std::cin >> time;
  std::string example_1 = time;
  std::string example_2 = time;
  std::string example_3 = time;
  func1(example_1);
  std::cout << "Function 1 result: " << example_1 << std::endl;
  func2(example_2);
  std::cout << "Function 2 result: " << example_2 << std::endl;
  func3(example_3);
  std::cout << "Function 3 result: " << example_3 << std::endl;
}
