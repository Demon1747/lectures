#include <iostream>
#include <thread>

void foo(const std::string& num) {
  for (size_t i = 0; i < 10000; ++i) {
    std::cout << i << " from " << num << std::endl;
  } 
}

int main() {
  std::thread th1(foo, "Thread 1");
  std::thread th2(foo, "Thread 2");
  th1.detach();
  th2.detach();
}
