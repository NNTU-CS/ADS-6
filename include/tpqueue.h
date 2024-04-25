// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T, int size>
class TPQueue {
 private:
  T arr[size];
  int begin, end, count;

 public:
  TPQueue() : begin(0), end(0), count(0) {}
  ~TPQueue() {}
  void push(const T& item) {
    assert(count < size);
    count++;
    int i = end;
    while (i != begin && item.prior > arr[(i - 1 + size) % size].prior) {
      arr[i % size] = arr[(i - 1 + size) % size];
      i = (i - 1 + size) % size;
    }
    arr[i % size] = item;
    end = (end + 1) % size;
  }
  T pop() {
    assert(count > 0);
    T item = arr[begin++ % size];
    count--;
    return item;
  }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
