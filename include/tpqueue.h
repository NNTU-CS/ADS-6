// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  T* Array;
  int first, last, count;

 public:
  TPQueue(): Array(new T[size]), first(0), last(0), count(0) {}
  void push(const T & value) {
    if (count == size)
      throw std::string("FULL!");
    ++count;
    int mesto = last;
    //находим нужную позицию
    for (int i = first; i < last; i++)
      if (Array[i].prior < value.prior) {
        mesto = i;
        break;
      }
    //сдвигаем
    for (int i = last; i> mesto; i--)
      Array[i % size] = Array[(i - 1) % size];
    //вставляем value
    Array[mesto % size] = value;
    ++last;
  }
  T& pop() {
    if (count == 0) {
      throw std::string("EMPTY!");
    } else {
      count--;
      return Array[first++ % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
