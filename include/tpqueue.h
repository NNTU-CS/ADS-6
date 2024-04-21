// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
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
        throw std::string("full!");
      }
      int k = end;
      for (int i = begin; i < end; i++) {
        if (array[i].prior < item.prior) {
          k = i;
          break;
        }
      }
      for (int i = end - 1; i >= k; i--) {
        array[(i + 1) % size] = array[i % size];
      }
      array[k % size] = item;
      begin++;
    }
    T pop() {
      if (cnt > 0) {
        T item = array[begin];
        begin = (begin + 1) % size;
        cnt--;
        return item;
      }
      throw std::string("Queue empty");
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
