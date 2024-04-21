// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

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

    void push(const T& elem) {
        if (count == capacity) {
            throw std::out_of_range("Queue is full");
        }

        std::size_t i = count;
        while (i > 0 && mass[i - 1].prior >= elem.prior) {
            mass[i] = mass[i - 1];
            --i;
        }
        mass[i] = elem;
        ++count;
    }

    T pop() {
        if (count == 0) {
            throw std::out_of_range("Queue is empty");
        }

        T tmp = mass[count - 1];
        --count;
        return tmp;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
