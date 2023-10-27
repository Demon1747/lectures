---
theme : "night"
transition: "slide"
highlightTheme: "vs"
slideNumber: true
---
<style type="text/css">
  .reveal pre code {
    font-size: 1em;
    line-height: 1.2;
    height: 200%;
    max-height: 1000% !important;
  }
  .reveal section p {
    display: inline-block;
    font-size: 0.9em;
    line-height: 1em;
    vertical-align: top;
  }

  .reveal section li {
    font-size: 0.9em;
    line-height: 1em;
    vertical-align: top;
  }

  .reveal section table {
    display: inline-block;
    font-size: 0.7em;
    line-height: 1.2em;
    vertical-align: top;
  }

</style>
[comment]: <> (highlightTheme: "darkula")

#### Сибирь I
## Структуры

--

#### Проверка остаточных знаний

--

Что такое контейнеры?

--

Что такое итераторы?

--

## Задача
Создать свою базу данных

--

### Пример
![](/src/database.png)

--

### Можем ли мы это сделать уже сейчас?

--

![](/src/5fbfeb03dcacd.jpg)

--

#### Вроде того

```cpp
std::map<std::string, std::string> category;
std::map<std::string, std::string> product_name;
std::map<std::string, unsigned int> sum;
...

// Новый заказ от Neofarm
customer = "Neofarm";
category[customer] = "Vitamines";
product_name[customer] = "Ascorbinka";
sum[customer] = 42000;
```

--

#### Смущает ли что-нибудь?

--

Новый запрос заказчика перетирает старый

#### Неудобно, нужно что-то ещё

---

### Структуры

> Это производные типы данных, включающие в себя множество элементов разных типов

--

```cpp
struct order {
  // поля структуры
  char category[64]; // плохо
  std::string product_name; // гораздо лучше
  std::string date;
  unsigned int cost;
  std::string customer;
};

int function() {
  order example = {
    "Vitamines",
    "Askorbinki",
    "17.10.2022",
    42000,
    "Neofarm"
  };
  ...
}
```

--

#### Другие способы инициализации
```cpp
int function() {
  order example;
  example.category = "Vitamines";
  example.product_name = "Askorbinki";
  example.date = "17.10.2022";
  example.cost = 42000;
  example.customer = "Neofarm";

  order example_2 {"str", "str", "str", 1000, "str"};  // C++11

  order zero_order {};  // устанавливает все поля в 0  
  zero_order = example;
  ...
}
```

--

#### В контейнерах тоже красиво

```cpp
int function() {
  // будет использоваться только внутри функции
  struct pair {
    int first,
    int second
  };

  int x1 = 1;
  int x2 = 2;
  int y1 = 3;
  int y2 = 4;

  std::vector<pair> pairs ({{x1, x2}, {y1, y2}});
  std::cout << pairs[0].first << ' ' << pairs[0].second;
  ...
}
```

--

### Немного о структурах в памяти

```cpp
// сколько структура занимает места в памяти?

struct Foo {
char c;    // 1 bytes
int iiii;  // 4 bytes
};
```

--

#### В данном случае поле char дополняется 3-мя байтами

```cpp
struct Foo {
char c;    // 1 bytes
int iiii;  // 4 bytes
};         // sizeof(Foo) == 8
```

--

### 

```cpp
struct Foo {  // для выравнивания размер кратен 4 байтам
int iiii;
char c;
};            // sizeof(Foo) == 8

struct Bar {  // для выравнивания размер кратен 1 байту
char c8[8];
};            // sizeof(Bar) == 8

struct Test1 {
char c;
Foo foo;
};

struct Test2 {
char c;
Bar bar;
};
```

--

```cpp
struct Foo {  // для выравнивания размер кратен 4 байтам
int iiii;
char c;
};            // sizeof(Foo) == 8

struct Bar {  // для выравнивания размер кратен 1 байту
char c8[8];
};            // sizeof(Bar) == 8

struct Test1 {  // для выравнивания размер кратен 4 байтам
char c;
Foo foo;
};            // sizeof(Test1) == 12

struct Test2 {  // для выравнивания размер кратен 1 байту
char c;
Bar bar;
};            // sizeof(Test2) == 9
```

--

#### Выравнивание
> Это свойство адреса в памяти, согласно которому адрес переменной в памяти должен быть кратен её размеру

Данные в памяти могут идентифицироваться по адресу в памяти

--

### Примерчик

```cpp
struct x_ {
   char a;     // 1 byte
   int b;      // 4 bytes
   short c;    // 2 bytes
   char d;     // 1 byte
} bar[3];

struct actual_x_ {
   char a;           // 1 byte
   char _pad0[3];    // выравнивание 'b' по 4-байтной границе
   int b;            // 4 bytes
   short c;          // 2 bytes
   char d;           // 1 byte
   char _pad1[1];    // выравнивние sizeof(x_) для кратности 4
} actual_bar[3];
```

--

![](./src/Sizes.jpg)

--

### Внимание -- нелинейность

--

Примешь синюю таблетку — и сказке конец. Ты отправишься делать лабу и поверишь, что это был сон. Примешь красную таблетку — войдешь в страну ООП.
![](/src/maxresdefault.jpg)

--

### В С++ структуры почти не отличаются от классов

--

## Классы
> Это производные типы, включающие в себя множество элементов различных типов данных и методы их обработки

--

> Типы, объявляемые ключевыми словами `class` и `struct` являются **_классами_**?

--

#### Найдите 10 отличий 

```cpp
struct order {
  std::string category;
  std::string product_name;
  unsigned int cost;
  std::string customer;
};

class order_analog {
 public:
  std::string category;
  std::string product_name;
  unsigned int cost;
  std::string customer;
};
```

--

#### У классов и структур также есть

1. Спецификаторы доступа
    * public
    * private
    * protected
2. Методы

--

![](./src/we_need_to_go_deeper.jpeg)

--

> У `struct` все поля по умолчанию **публичные**, у `class` -- **приватные** 

--

### Спецификаторы доступа

```cpp
class order {
 public:  // доступны вне класса
  std::string category;
  std::string product_name;
  unsigned int cost;

 private:  // доступны только внутри класса
  std::string customer;
};

int function() {
  order example = {...};
  std::cout << example.cost << std::endl;  // можно 
  std::cout << example.customer << std::endl;  // нельзя  
}
```

--

### Методы

```cpp
class order {
  ...
 public:  // Доступно извне
  void print_customer() {  // описание метода
    std::cout << "Order " << order_id << "customer: " << customer << std::endl;
  }

 private:  // Доступно только внутри класса
  std::string customer;
};

int function() {
  order example = {...};

  // Можно
  example.print_customer();
}
```

---

### Еще пара отступлений

--

### Битовые поля в структурах

Типы должны быть перечислимыми или целочисленными

```cpp
struct register {
  int var_1 : 4;      // значение занимает 4 бита
  int var_2 : 4;
  int : 4;            // пропуск 4 бит
  bool flag : 1;      // занимает 1 бит
  bool good : 1
};
```

Нужно в низкоуровневом программировании

--

### Объединения (Union)

> В одной области могут храниться данные, которые могут читаться по-разному -- в зависимости от требуемого в конкретный момент типа данных

--

```cpp
union one4all {
  int int_val;
  long long_val;
  double double_val;
};

int function() {
  one4all example;
  example.int_val = 42;
  std::cout << example.int_val << std::endl;
  example.double_val = 3.1415926;
  std::cout << example.double_val << std::endl;
}
```

--

### Нужны ли они нам?

--

![](/src/16a16e0ed60cb0910526a4554a06b36c.jpg)
