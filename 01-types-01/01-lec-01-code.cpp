#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << "Write your password: ";
  std::string pw;
  std::cin >> pw;

  /// Size check
  if (pw.size() < 8) {
    std::cout << "Password is not safe" << std::endl;
    return -1;
  }

  std::vector<char> symbols({'_', '-', '*', '!'});
  bool flag_sym = false;
  bool flag_num = false;
  bool flag_big = false;
  bool flag_low = false;

  /// Cycle
  for (size_t i = 0; i < pw.size(); ++i) {
    if (pw[i] >= '0' && pw[i] <= '9' && !flag_num) {
      flag_num = true;
      continue;
    }
    if (pw[i] >= 'A' && pw[i] <= 'Z') {
      flag_big = true;
      continue;
    }
    if (pw[i] >= 'a' && pw[i] <= 'z') {
      flag_low = true;
      continue;
    }
    for (auto sym : symbols) {
      if (sym == pw[i]) {
        flag_sym = true;
        break;
      }
    }

    if (flag_num && flag_sym && flag_big && flag_low) {
      std::cout << "Your password is safe" << std::endl;
      return 0;
    }
  }

  std::cout << "Your password is not safe" << std::endl;
  return -1;
}
