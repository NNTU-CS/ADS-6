// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <stdexcept>
#include <cstddef>
template<typename T, int size>
class TPQueue {
private:
    T* mass;
    std::size_t capacity;
    std::size_t count;

 public:
    TPQueue() : mass(new T[size]), capacity(size), count(0) {}

    ~TPQueue() {
        delete[] mass;
    }

    void push(const T& item) {
        if (count < size) {
            if (count == 0) {
                arr[count++] = item;
            } else {
                int i = count - 1;
                while (i >= 0 && item.prior > arr[i].prior) {
                    arr[i + 1] = arr[i];
                    i--;
                }
                arr[i + 1] = item;
                count++;
            }
        } else {
            std::cerr << "Queue is full" << std::endl;
        }
    }

    T pop() {
        if (count > 0) {
            return arr[--count];
        } else {
            std::cerr << "Queue is empty" << std::endl;
            return T();
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
