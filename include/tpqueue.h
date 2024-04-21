// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  T* arr;
  int first, last, count;

 public:
  TPQueue(): arr(new T[size]), first(0), last(0), count(0) {}
  void push(const T & data) {
    if (count == size)
      throw std::string("FULL!");
    ++count;
    int pos = last;
    for (int i = first; i < last; i++)
      if (arr[i].prior < data.prior) {
        pos = i;
        break;
      }
    for (int i = last; i> pos; i--)
      arr[i % size] = arr[(i - 1) % size];
    arr[pos % size] = data;
    ++last;
  }
  T& pop() {
    if (count == 0) {
      throw std::string("EMPTY!");
    } else {
      count--;
      return arr[first++ % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
