#include <iostream>
#include <algorithm>
#include <vector>

#include "header.h"
using std::cout;

int find_test(); /// Объявление функции

//using namespace Google;
//using namespace Yandex;

int main() {
  find_test();
  return 0;
}

int find_test() {
  std::vector<int> array({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  auto res = std::find(array.begin(), array.end(), 8);
  cout << *res;
  return 0;
}
