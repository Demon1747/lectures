#include <algorithm>
#include <iostream>
#include <limits>
#include <ranges>
#include <string>
#include <map>
#include <vector>

void algorithm_ex() {
  std::vector<int> nums = {0, 1, 2, 3, 4, 5};

  std::vector<int> result;
  std::copy_if(nums.begin(), nums.end(), std::back_inserter(result),
               [](int x) { return x % 2 == 0; });
  std::transform(result.begin(), result.end(), result.begin(),
                 [](int x) { return x * 2; });

  for (auto v : result) {
    std::cout << v << ' ';
  }

  std::cout << std::endl;
}

void ranges_ex() {
  std::vector<int> nums = {0, 1, 2, 3, 4, 5};

  auto result = nums | std::views::filter([](int n) { return n % 2 == 0; }) |
                std::views::transform([](int n) { return n * 2; });

  for (auto v : result) {
    std::cout << v << ' ';
  }

  nums = {0, 1, 2};

  for (auto v : result) {
    std::cout << v << ' ';
  }

  std::cout << std::endl;
}

void map_ex() {
  std::map<std::string, int> freqWord{{"witch", 25}, {"wizard", 33},
                                      {"tale", 45},  {"dog", 4},
                                      {"cat", 34},   {"fish", 23}};
  std::cout << "Keys:" << std::endl;
  for (const auto& name : std::views::keys(freqWord)) {
    std::cout << name << " ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "Values: " << std::endl;
  for (const auto& value : std::views::values(freqWord)) {
    std::cout << value << " ";
  }

  std::cout << std::endl;
}

bool greater(int a, int b) { return a > b; }

void my_sort() {
  std::vector<int> nums = {1, 2, 3, 0, 4, 5};
  std::sort(nums.begin(), nums.end(), greater);

  for (auto v : nums) {
    std::cout << v << ' ';
  }

  std::cout << std::endl;
}

void infinity() {
  std::vector<int*> pointers;

  while (true) {
    pointers.push_back((int*)malloc(std::numeric_limits<size_t>::max()));
  }
}

int main() {
  algorithm_ex();
  ranges_ex();
  my_sort();
  map_ex();
  return 0;
}