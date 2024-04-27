// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int first;
    int last;

 public:
    TPQueue() :first(0), last(0), arr(new T[size]) { }
    void push(T x) {
        if (last - first >= size)
            throw std::string("Full!");
        int index = last;
        for (int i = first; i < last; i++) {
            T s = arr[i % size];
            if (x.prior > s.prior) {
                index = i;
                break;
            }
        }
        for (int i = last - 1; i >= index; i--) {
            arr[(i + 1) % size] = arr[i % size];
        }
        arr[index % size] = x;
        last++;
    }
    T pop() {
        T x = arr[first % size];
        arr[first % size].prior = -1;
        arr[first % size].ch = 0;
        first++;
        return x;
    }
    int getSize() {
        return (last - first);
    }
    T front() {
        return arr[first % size];
    }
    T back() {
        return arr[(last - 1) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
