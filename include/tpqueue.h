// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
  T* arr;
  int last, first, count;

 public:
  TPQueue() : last(0), first(0), count(0) {
    arr = new T[size];
  }
  bool isEmpty() const {
    return 0 == count;
  }
  bool isFull() const {
    return count == size;
  }
  void push(const T& value) {
    if (isFull()) {
      throw std::string("Full");
    } else {
      int i = last;
      arr[last % size] = value;
      T tmp = arr[i % size];
      while (arr[i % size].prior > arr[(i - 1) % size].prior && i > first) {
        tmp = arr[i % size];
        arr[i % size] = arr[(i - 1) % size];
        arr[(i - 1) % size] = tmp;
        i--;
      }
      count++;
      last++;
    }
  }
  const T& pop() {
    if (isEmpty()) {
      throw std::string("Empty");
    } else {
      --count;
      return arr[first++%size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
