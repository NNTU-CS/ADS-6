// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>
#include <iostream>

struct SYM {
    char ch;
    int prior;
};

template<typename T, int size>
class TPQueue {
 private:
    T* array;
    int start;
    int finish;
    int count;

 public:
    TPQueue() {
        start = 0;
        finish = 0;
        count = 0;
        array = new T[size];
    }

    ~TPQueue() {
        delete[] array;
    }

    void push(const T& item) {
        assert(count < size);
        count++;
        int pe = finish;
        for (int i = start; i < finish; i++) {
            if (array[i].prior < item.prior) {
                pe = i;
                break;
            }
        }
        for (int i = finish - 1; i >= pe; i--) {
            array[(i + 1) % size] = array[i % size];
        }
        array[pe % size] = item;
        finish++;
    }

    T pop() {
        assert(count > 0);
        count--;
        T item = array[start];
        start = (start + 1) % size;
        return item;
    }
};
#endif  // INCLUDE_TPQUEUE_H_
