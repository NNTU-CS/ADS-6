// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
// реализация шаблона очереди с приоритетом на кольцевом буфере
T* arr;
int arrSize, head, tail, count;

 public:
  TPQueue(): head(0), tail(0), count(0), arrSize(0) {
     arr = new T[arrSize + 1];
  }

  ~TPQueue() {
     delete[] arr;
  }

  void push(const T& item) {
     if (count == arrSize) {
           throw std::string("full");
     } else if (tail == head) {
       arr[tail++] = item;
     } else {
       int i = 0;
       for (i = end; i >= head; i--) {
         if (arr[i].prior < item.prior) {
           arr[i+1] = arr[i];
       } else {
         break;
       }
       arr[i+1] = item;
       tail++;
       }
     }
  }

  T pop() {
     if (count == 0) {
           throw std::string("empty");
     }
     SYM res = arr[0];
     for (int i = 0; i < count - 1; ++i) {
         arr[i] = arr[i + 1];
     }
     count--;
     return res;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_T*arr;H_
