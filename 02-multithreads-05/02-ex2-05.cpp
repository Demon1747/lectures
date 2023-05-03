#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::vector<size_t> nums;
size_t i;
std::mutex my_mutex;

void foo(const std::string& num) {
  for (; i < 100; ++i) {
    {
      std::lock_guard<std::mutex> guard(my_mutex);
      nums.push_back(i);
    }

    std::cout << i << " from " << num << std::endl;
  } 
}

int main() {
  std::thread th1(foo, "Thread 1");
  std::thread th2(foo, "Thread 2");
  th1.join();
  th2.join();
}
