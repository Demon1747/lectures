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

#### Сибирь I
## Память
#### и вновь немного ООП

--

#### В предыдущих сериях

--

### Виды памяти

- `static` -- _хранилище глобальных переменных_
- `stack` -- _хранилище локальных переменных (и не только)_
- `heap` -- _динамическая память (много памяти)_

--

### Зачем оно вообще нужно?

--

### Лучше один раз увидеть

--

![](/src/cumburger.png)

--

![](/src/another-picture.jpg)

--

![](/src/data-scheme.png)

---

Микромемчик

![](/src/cat.jpg)

--

## static memory
- Существует в течение всего времени работы программы
- Переменные являются статическими, существуют в единственном экземпляре и доступны в любом месте программы

--

## stack memory
- Контролируется CPU
- С его помощью программа вообще работает
- Переменые являются локальными
- С изменением количества переменных меняется и стек
- Стек не бесконечен

--

![](/src/local.jpg)

--

## heap memory
- Контролируется программистом
- `new` и `delete` --  наше всё
- Для доступа требуются указатели
- Как правило ограничивается количеством доступной физической памяти

--

указатели

---

### Указатель
>Это тип данных, в котором хранится адрес памяти объекта (число)

--

### Не путать с ссылками!
>Ссылка -- альтернативное имя переменной

--

### Примеры
```cpp
int* p = new int(17);  // создаём объект
std::cout << *p << std::endl;
delete p;  // удаляем объект

int* arr = new int[n];  // выделяем область памяти
for (size_t i; i < n; ++i) {  // докупаем
  p[i] = 0;
}
delete[] arr;  // фиксируем прибыль
```

--

#### Одним измерением и ограничимся?

--

![](/src/pointers.webp)

--

```cpp
int** arr = new int*[n2];  // создаём указатель на указатель
for (size_t i; i < n2; ++i) { 
  arr[i] = new int[n1];  // выделяем память
}

for (size_t i; i < n2; ++i) {  // освобождаем в том же порядке
  delete[] arr[i];             // что и выделяли
}
delete[] arr;
```

--

### Двумя измерениями и ограничимся?

--

![](/src/pointer-ception.png)

--

![](/src/pointer-pointer.png)

--

### А как теперь жить?

---


#### Небольшой list

* `std::find`
* `std::find_if`
* `std::count_if`
* `std::transform`
* `std::sort`
* `std::any_of`
* `std::for_each`

--

### std::find

Возвращает итератор на первый элемент, равный `value`

```cpp
template< class InputIt, class T >
InputIt find( InputIt first, InputIt last, const T& value);
```

--

### std::find_if

Возвращает итератор на первый элемент, удовлетворяющий условию `pred`

```cpp
template<class InputIterator, class Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate pred);
```

--

### std::any_of

Проверяет, выполняется ли pred хоть для одного элемента последовательности

```cpp
template< class InputIt, class UnaryPredicate >
bool any_of(InputIt first, InputIt last, UnaryPredicate pred);
```

--

### std::count_if

Возвращает количество элементов, удовлетворяющих условию `pred`

```cpp
template< class InputIt, class UnaryPredicate >
typename iterator_traits<InputIt>::difference_type
count_if(InputIt first, InputIt last, UnaryPredicate pred);
```

--

### std::for_each

Выполняет функцию для каждого элемента

```cpp
template< class InputIt, class UnaryFunction >
UnaryFunction for_each( InputIt first, InputIt last, UnaryFunction f );
```

--

### std::transform

Возвращает результат применения функции к каждому элементу последовательности

```cpp
template <class InIter, class OutIter, class Funс>
OutIter transform(InIter start, InIter end,
		  OutIter result, Func unaryfunc);
```

--

### std::sort
Сортирует

```cpp
template<class RandomAccessIterator>
void sort(RandomAccessIterator first,
          RandomAccessIterator last);

template<class RandomAccessIterator, class Predicate>
void sort(RandomAccessIterator first,
          RandomAccessIterator last,
          Predicate comp);
```

---

### lambda functions
aka. анонимные функции

--

![](/src/lambda)
