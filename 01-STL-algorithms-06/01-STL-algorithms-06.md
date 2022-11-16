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
## STL Алгоритмы

--

>STL -- Standard Template Library

--

Библиотека STL содержит набор шаблонов, представляющих контейнеры, итераторы, объекты функций и алгоритмов

--

#### Зачем оно вообще нужно?

--

#### Вот они (контейнеры) слева направо
![](/src/Diagramme_UML_de_STL.png)

--

#### Возьмём std::vector
Часто ли приходится его сортировать, искать в нем элементы?

--

### А в std::list?

--

> Идея STL -- обобщенное программирование -- создание кода, **не зависящего от типа данных**  

--

#### Вот они (алгоритмы) сверху вниз
![](/src/algorithms.png)

--

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
