#include <iostream>
#include <vector>

int main() {
  /// Vector methods

  std::vector<char> symbols({'_', '-', '*', '!'});

  /// Adding few elements
  symbols.push_back('h');
  symbols.insert(symbols.begin() + 2, 'm');

  /// Printing vector
  for (auto i : symbols) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;

  /// Deleting few symbols
  symbols.erase(symbols.begin() + 2);
  symbols.erase(symbols.begin() + symbols.size() - 1);

  /// Printing vector
  for (auto i : symbols) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;

  return 0;
}
