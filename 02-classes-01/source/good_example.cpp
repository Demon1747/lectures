#include <algorithm>
#include <concepts>
#include <vector>

template <class T>
concept IterToComparable = requires(T a, T b) {
  { *a < *b } -> std::convertible_to<bool>;
};

template <IterToComparable InputIt>
void SortDefaultComparator(InputIt begin, InputIt end) {
  std::sort(begin, end);
}

struct X {
  int a;
};

int main() {
  std::vector<X> v = {{10}, {9}, {11}};
  SortDefaultComparator(v.begin(), v.end());
}
