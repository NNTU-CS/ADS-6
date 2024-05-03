// Copyright 2022 NNTU-CS
#include <string>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T *data;
    int head, t, cnt;
 public:
    TPQueue() : head(0), t(0), cnt(0), data(new T[size]) {}
    void push(const T& item) {
        if (cnt >=size) {
            throw std::string("full");
        }
        int index = t;
        cnt++;
        for (int i = head; i < t; i++) {
            if (data[i].priory < item.priory) {
                index = i;
                break;
            }
        }
        for (int i = t; i > index; i--) {
            data[i % size] = data[(i - 1) % size];
        }
        data[index % size] = item;
        t++;
    }
    T pop() {
        if (cnt == 0) {
            throw std::string("empty!");
        } else {
            cnt--;
            return data[head++ % size];
        }
    }
};
struct SYM {
  char ch;
  int priory;
};
#endif  // INCLUDE_TPQUEUE_H_
