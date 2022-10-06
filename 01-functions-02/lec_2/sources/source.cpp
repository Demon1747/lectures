#include <iostream>
#include <vector>
#include "header.h"

/// Namespace
size_t Yandex::results_number(const std::string& search) {
  std::vector<std::string> data(20, search);
  return data.size();
}

size_t Google::results_number(const std::string& search) {
  std::vector<std::string> data(15, search);
  return data.size();
}

/// Область видимости
void function() {
  size_t i = 5;
  std::cout << i << std::endl;
  for (size_t j = 0; j < 3; ++j) {
    size_t i = 2;
    std::cout << i << std::endl;
  }
  if (i > 0) {
    int x = 10;
  }
//  x = 5;
//  std::cout << x << std::endl;
}
