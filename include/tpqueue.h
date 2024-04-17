// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
private:
    int begin, end, count;
    T *data;
public:
    TPQueue() : begin(0), end(0), count(0), data(new T[size]) {}
    void push(const T & item) {
        int i = end;
        if (count >= size) {
            throw std::string("is full");
        }
        count++;
        while (begin < end) {
            if (item.prior > data[begin].prior) {
                end = begin;
                break;
            }
            begin++;
        }
        for (; i > end; i--)
            data[i % size] = data[(i - 1) % size];
            data[end % size] = item;
            end++;
    }
  
    T pop() {
        if (count == 0) {
            throw std::string("is empty");
        }
        else {
            count--;
            return data[(begin++) % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
