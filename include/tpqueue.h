// Copyright 2022 NNTU-CS
#include <string>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T *arr;
    int head, t, cnt;

 public:
    TPQueue() : head(0), t(0), cnt(0), arr(new T[size]) {}
    void push(const T& item) {
        if (cnt >=size) {
            throw std::string("full");
        }
        int index = t;
        cnt++;
        for (int i = head; i < t; i++) {
            if (arr[i].prior < item.prior) {
                index = i;
                break;
            }
        }
        for (int i = t; i > index; i--) {
            arr[i % size] = arr[(i - 1) % size];
        }
        arr[index % size] = item;
        t++;
    }
    T pop() {
        if (cnt == 0) {
            throw std::string("empty!");
        } else {
            cnt--;
            return arr[head++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
