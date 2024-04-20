// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
  T* arr;
  int begin, end, count;

 public:
  TPQueue() : begin(0), end(0), count(0) { arr = new T[size]; }

  ~TPQueue() { delete[] arr; }

  void push(const T& sym) {
    if (count >= size) throw std::string("queue full");
    count++;
    int pos = end;
    for (int i = begin; i < end; i++) {
      if (arr[i].prior < sym.prior) {
        pos = i;
        break;
      }
    }
    for (int i = end - 1; i >= pos; i--) arr[(i + 1) % size] = arr[i % size];
    arr[pos % size] = sym;
    end++;
  }

  T pop() {
    if (count == 0) {
      throw std::string("Empty");
    } else {
      count--;
      return arr[begin++ % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
