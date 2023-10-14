// Copyright Demon1747

#ifndef PW_HEADER_HEADER_H_
#define PW_HEADER_HEADER_H_

#include <string>
#include <vector>

// find competitor
template<class InputIt>
InputIt find(InputIt first, InputIt last, int value) {
  std::vector<int> array(10, 5);
  return array.begin();
}

// Namespace
namespace Yandex {
  size_t results_number(const std::string&);
}

namespace Google {
  size_t results_number(const std::string&);
}

void test_namespace();

// Область видимости
void function();


#endif //PW_HEADER_HEADER_H_
