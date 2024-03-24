#include <vector>
#include <algorithm>
#include <string>

// Часть, относящаяся к классам
class Order {
 public:
  Order() = default;
  Order(const Order& copy_item) : category(copy_item.category) {}
  Order(unsigned int my_cost) : cost(my_cost) {}

  ~Order() {
    delete[] ptr;
  }

 public:  // доступны вне класса
  std::string category;
  std::string product_name;
  unsigned int cost;
  int* ptr;
  
  Order& operator=(const Order& b) {
    category = b.category;
    return *this;
  }
  Order& operator+(const Order& b) {
  }
 
 private:  // доступны только внутри класса
  std::string customer;
};
//ЗДесь хороший код заканчивается

struct X {
  int a;
};

int main() {
  std::vector<X> v = {{10}, {9}, {11}};
  // сортируем вектор
  std::sort(v.begin(), v.end());
}
