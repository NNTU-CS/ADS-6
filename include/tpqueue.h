// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T *arr;
    int top, end, count;

 public:
    TPQueue() : top(0), end(0), count(0), arr(new T[size]) {}
    T pop() {
        if (count == 0) {
            throw std::string("Is empty");
        } else {
            count--;
            return arr[top++ % size];
        }
    }
    void push(const T &item) {
        if (count >= size) {
            throw std::string("Is full");
        }
        count++;
        int iend = end;
        int itop = top;
        while (itop < end) {
            if (arr[itop].prior < item.prior) {
                iend = itop;
                break;
            }
            itop++;
        }
        for (int i = end; i > iend; i--)
            arr[i % size] = arr[(i - 1) % size];
        arr[iend % size] = item;
        end++;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
