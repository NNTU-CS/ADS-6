// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<class T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    int first;
    int last;
    T* arr;

 public:
    TPQueue():first(0), last(0) {
    arr = new T[size + 1];
    for (int i = 0; i < size; i++)
        arr[i] = { '-', 0 };
    }
    ~TPQueue() {
        delete []arr;
    }
    void push(T sim) {
        if (last - first == size) {
            throw std::string("Full!");
        } else {
          if (last == first) {
                arr[last++] = sim;
          } else {
              int i = last-1;
              while (i >= 0 && sim.prior <= arr[i].prior) {
                arr[i + 1] = arr[i];
                i--;
              }
              arr[i + 1] = sim;
              last++;
            }
        }
    }
    T pop() {
        return arr[--last];
    }
};

struct SYM {
  char ch;
  int prior;
  SYM() {};
  SYM(char c, int p) :ch(c), prior(p) {}
};

#endif  // INCLUDE_TPQUEUE_H_
