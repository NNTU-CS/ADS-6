// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
class TPQueue {
  T* array;
  int head1, tail, counter;

 public:
  TPQueue(): array(new T[size]), head1(0), tail(0), counter(0) {}
  void push(const T & value) {
    if (counter == size)
      throw std::string("Full!");
    ++counter;
    int number = tail;
    for (int j = head1; j < tail; j++)
      if (array[j].prior < value.prior) {
        number = j;
        break;
      }
    for (int j = tail; j > number; j--)
      array[j % size] = array[(j - 1) % size];
    array[number % size] = value;
    ++tail;
  }
  T & pop() {
    if (counter == 0) {
      throw std::string("Полон!");
    } else {
      counter--;
      return array[head1++ % size];
    }
  }
};
#endif  // INCLUDE_TPQUEUE_H_
