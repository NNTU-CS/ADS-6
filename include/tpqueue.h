// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* array;
    int cnt, begin, end;

 public:
    TPQueue() : begin(0), end(0), cnt(0) {
      array = new T[size];
    }
    ~TPQueue() {
      delete[] array;
    }

    void push(const T& item) {
      if (cnt >= size) {
        throw std::out_of_range("Queue is full!");
      }
      int k = end - 1;
      while (k >= begin && array[k % size].prior < item.prior) {
       array[(k + 1) % size] = array[k % size];
       k--;
      }
      array[(k + 1) % size] = item;
      end++;
      cnt++;
    }
    T pop() {
      if (cnt > 0) {
        T item = array[begin];
        begin = (begin + 1) % size;
        cnt--;
        return item;
      }
      throw std::out_of_range("Queue is empty!");
    }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
