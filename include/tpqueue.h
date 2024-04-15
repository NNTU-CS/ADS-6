// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept> 
#include <utility>   

template<typename T, int size>
class TPQueue {
    T *Array;
    int lol, elementkon, counter;
public:
    TPQueue() : Array(new T[size]), lol(0), elementkon(0), counter(0) {}
    ~TPQueue() {
        delete[] Array;
    }
    void push(const T &value) {
        if (counter == size)
            throw std::overflow_error("full");
        int insertIndex = elementkon;
        for (int i = lol; i < elementkon; ++i) {
            if (Array[i].prior < value.prior) {
                insertIndex = i;
                break;
            }
        }
        for (int i = elementkon; i > insertIndex; --i) {
            Array[i % size] = Array[(i - 1) % size];
        }
        Array[insertIndex % size] = value;
        ++elementkon;
        ++counter;
    }

    T pop() {
        if (counter == 0)
            throw std::underflow_error("pop");

        --counter;
        return Array[lol++ % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
