// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
// реализация шаблона очереди с приоритетом на кольцевом буфере
T* arr;
int head, tail, count;

 public:
  TPQueue(): head(0), tail(0), count(0) {
     arr = new T[size];
  }

  ~TPQueue() {
     delete[] arr;
  }

  void push(const T& item) {
     if (count == size) {
           throw std::string("full");
     } else {
       int i = tail;
       while (i != head && arr[i-1].prior >= item.prior) {
           arr[i] = arr[i-1];
           i = (i - 1 + size) % size;
       }
       arr[i] = item;
       tail = (tail + 1) % size;
       count++;
       }
  }

  T pop() {
     if (count == 0) {
      throw std::string("empty");
     } else {
      T item = arr[head];
      head = (head + 1) % size;
      count--;
      return item;
     }
  }
};


struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
