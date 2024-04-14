// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T, int size>
class TPQueue {
 private:
    T* array;
    int begin, end, k;

public:
    TPQueue() : begin(0), end(0), k(0) {
        array = new T[size];
    }

    ~TPQueue() {
        delete[] array;
    }

    void push(const T& el) {
        if (k < size) {
            int i = k - 1;
            while (i >= 0 && el.prior > array[i].prior) {
                array[i + 1] = array[i];
                i--;
            }
            array[i + 1] = el;
            k++;
        } else {
            throw std::string("Queue is full");
        }
    }

    T pop() {
        if (k == 0) {
            throw std::string("Queue is empty");
        } else {
            k--;
            return array[begin++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
