// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <exception>

template<typename T, int size>
class TPQueue {
 private:
    int head, tail;
    int flag;
    T* data;

 public:
    TPQueue() : head(0), tail(0), flag(0), data( ( T* )malloc ( sizeof( T ) * size ) ) {}

    void push(const T& item) {
        if (flag >= size)
            throw std::overflow_error("Queue full!");
        flag++;
        int t1 = tail;
        for ( int h1 = head; h1 < tail; h1++ ) {
            if (data[h1].prior < item.prior) {
                t1 = h1;
                break;
            }
        }
        for (int i = tail; i > t1; i--)
            data[i % size] = data[(i - 1) % size];
        data[t1 % size] = item;
        tail++;
    }

    T pop() {
        if (flag == 0) {
            throw std::underflow_error("Queue empty!");
        } else {
            flag--;
            return data[(head++) % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
