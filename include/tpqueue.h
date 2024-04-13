// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
#include <stdexcept>

template<typename T, int size>
class TPQueue {
 private:
    int begin, end, count;
    T* data;

 public:
    TPQueue() : begin(0), end(0), count(0), data(new T[size]) {}

    T pop() {
        if (count == 0) {
            throw std::string("Empty!!!");
        } else {
            count--;
            T item = data[begin];
            begin = (begin + 1) % size;
            return item;
        }
    }

    void push(const T& item) {
        if (count >= size)
            throw std::string("Full!!!");

        int Index = end;
        count++;

        for (int i = begin; i < size; i++) {
            if (data[i].prior < item.prior) {
                Index = i;
                break;
            }
        }

        for (int i = end; i > Index; i--) {
            data[(i + 1) % size] = data[i % size];
        }

        data[Index % size] = item;
        end = (end + 1) % size;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
