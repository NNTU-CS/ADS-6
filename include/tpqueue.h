// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>
#include <cstddef>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    T* arr;
    std::size_t capacity;
    std::size_t count;

 public:
    TPQueue() : arr(new T[size]), capacity(size), count(0) {}

    ~TPQueue() {
        delete[] arr;
    }

    void push(const T& elem) {
        if (count == capacity) {
            throw std::out_of_range("Queue is full");
        }

        std::size_t i = count;
        while (i > 0 && arr[i - 1].prior >= elem.prior) {
            arr[i] = arr[i - 1];
            --i;
        }
        arr[i] = elem;
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
