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

    T pop() {
        if (count == 0) {
            throw std::string("Empty!!!");
        } else {
            count--;
            return data[begin++ % size];
        }
    }

    void push(const T &item) {
        if (count >= size)
            throw std::string("Full!!!");
        int Index = end;
        while (Index > begin && data[(Index - 1) % size].prior < item.prior) {
            data[Index % size] = data[(Index - 1) % size];
        }
        data[Index % size] = item;
        end = (end + 1) % size;
        count++;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
