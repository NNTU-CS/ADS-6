// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>

template<typename T, int size>
class TPQueue {
 private:
  struct ITEM {
    T data;
    int prior;
  };
  ITEM* arr;
  int begin;
  int end;
  int count;

 public:
  TPQueue() : begin(0), end(0), count(0) { arr = new ITEM[size]; }

  ~TPQueue() { delete[] arr; }

  bool isEmpty() const { return count == 0; }

  bool isFull() const { return count == size; }

  void push(const T& item) {
    if (isFull()) {
      std::cerr << "Error: Queue is full!\n";
      return;
    }
    int current = end;
    while (current != begin &&
           item.prior > arr[(current - 1 + size) % size].prior) {
      arr[current] = arr[(current - 1 + size) % size];
      current = (current - 1 + size) % size;
    }
    arr[current].data = item;
    arr[current].prior = item.prior;
    end = (end + 1) % size;
    count++;
  }

  T pop() {
    if (isEmpty()) {
      std::cerr << "Error: Queue is empty!\n";
    }
    T item = arr[begin].data;
    begin = (begin + 1) % size;
    count--;
    return item;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
