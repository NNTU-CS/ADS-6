// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int size>
class TPQueue {

  private: 
    int start, end, count;
    T *data;

  public: 
    TPQueue() : start(0), end(0), count(0), data(new T[size]) {}
    void push(const T &item) {
        if (count >= size) {
            throw std::string("queue is full");
        }
        count++;
        int ind = end;
        for (int i = start; i < end; i++) {
            if (data[i].prior < item.prior) {
                ind = i;
                break;
            }
        }
        for (int i = end; i > ind; i--)
            data[i % size] = data[(i - 1) % size];
        data[ind % size] = item;
        end++;
    }
    T pop() {
        if (count == 0) {
            throw std::string("queue is empty");
        } else {
            count--;
            return data[start++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
