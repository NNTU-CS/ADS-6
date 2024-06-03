// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <stdexcept>
#include <cstddef>
template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    std::size_t capacity;
    std::size_t count;

 public:
    TPQueue() : arr(new T[size]), capacity(size), count(0) {}

    ~TPQueue() {
        delete[] arr;
    }

    void push(const T& item) {
        if (count == capacity) {
            std::cerr << "Queue is full" << std::endl;
        }

        std::size_t i = count - 1;
        while (i >= 0 && arr[i].prior >= item.prior) {
        arr[i + 1] = arr[i];
              i--;
        }
        arr[i + 1] = item;
        count++;
    }

    T pop() {
        if (count == 0) {
            std::cerr << "Queue is empty" << std::endl;
        }
        T tmp = arr[count - 1];
        count--;
        return tmp;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
