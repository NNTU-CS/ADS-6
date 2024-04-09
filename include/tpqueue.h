// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  T* arr;
  int head, tail, count;

 public:
  TPQueue(): arr(new T[size]), head(0), tail(0), count(0) {}
  void push(const T & value) {
    if (count == size)
      throw std::string("Full!");
    ++count;
    int number = tail;
    for (int i = head; i < tail; i++)
      if (arr[i].prior < value.prior) {
        number = i;
        break;
      }
    for (int i = tail; i > number; i--)
      arr[i % size] = arr[(i - 1) % size];
    arr[number % size] = value;
    ++tail;
  }
  T & pop() {
    if (count == 0) {
      throw std::string("Empty!");
    } else {
      count--;
      return arr[head++ % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
