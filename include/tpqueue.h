// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>
#include <cstddef>

template<typename T, int size>
class TPQueue {
private:
    T* data;
    std::size_t capacity;
    std::size_t count;

 public:
    TPQueue() : data(new T[Size]), capacity(Size), count(0) {}

    ~TPQueue() {
        delete[] data;
    }

    void push(const T& elem) {
        if (count == capacity) {
            throw std::out_of_range("Queue is full");
        }

        std::size_t i = count;
        while (i > 0 && data[i - 1].prior >= elem.prior) {
            data[i] = data[i - 1];
            --i;
        }
        data[i] = elem;
        ++count;
    }
    T pop() {
        if (count == 0) {
            throw std::out_of_range("Queue is empty");
        }

    T tmp = arr[count - 1];
        --count;
        return tmp;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
