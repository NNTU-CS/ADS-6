// Copyright 2022 NNTU-CS
#include <string>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T *arr;
    int head, tail, count;

 public:
    TPQueue() : head(0), tail(0), count(0), arr(new T[size]) {}
    void push(const T& item) {
        if (count >=size) {
            throw std::string("full");
        }
        int index = tail;
        count++;
        for (int i = head; i < tail; i++) {
            if (arr[i].prior < item.prior) {
                index = i;
                break;
            }
        }
        for (int i = tail; i < index; i--) {
            arr[i % size] = arr[(i - 1) % size];
        }
        arr[index % size] = item;
        tail++;
    }
    T pop() {
        if (count == 0) {
            throw std::string("empty");
        } else {
            count--;
            return arr[head++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
