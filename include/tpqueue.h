// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>

template<typename T, int size>
class TPQueue {
 private:
  T* arr;
  int begin;
  int end;
  int count;

 public:
  TPQueue() : begin(0), end(0), count(0) { arr = new T[size]; }

  ~TPQueue() { delete[] arr; }

  bool isEmpty() const { return count == 0; }

  bool isFull() const { return count == size; }

  void push(const T& item) {
    if (isFull()) {
      std::cout << "Error: Queue is full!\n";
      return;
    }
    int temp = end - 1;
    if (temp < 0) temp = size - 1;
    while (temp >= 0 && arr[temp].prior < item.prior) {
      arr[(temp + 1) % size] = arr[temp];
      temp--;
    }
    arr[(temp + 1) % size] = item;
    end = (end + 1) % size;
    count++;
  }

  T pop() {
    if (isEmpty()) {
      std::cout << "Error: Queue is empty!\n";
    }
    T item = arr[begin];
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
