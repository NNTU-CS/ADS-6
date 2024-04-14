// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int size>
class TPQueue {
 private:
    int head, tail;
    int count;
    T *data;

 public:
    TPQueue() : head(0), tail(0), count(0), data(new T[size]) {}

    T pop() {
        if (count == 0) {
            throw std::string("empty");
        } else {
            count--;
            return data[(head + 1) % size];
        }
    }

    void push(const T &item) {
        if (count >= size) {
            throw std::string("full");
        }
        count++;
        int it = tail, ih = head;
        while (ih < tail) {
            if (data[ih].prior < item.prior) {
                it = ih;
                break;
            }
            ih++;
        }
        for (int i = tail; i > it; i--)
            data[i % size] = data[(i - 1) % size];
        data[it % size] = item;
        tail++;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
