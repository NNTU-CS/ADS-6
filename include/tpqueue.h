// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    int head, tail;
    int counter;
    T *data;

 public:
    TPQueue() : head(0), tail(0), counter(0), data(new T[size]) {}
    void push(const T &item) {
        if (counter >= size)
            throw std::string("Full");
        counter++;
        int t1 = tail, h1 = head;
        while (h1 < tail) {
            if (data[h1].prior < item.prior) {
                t1 = h1;
                break;
            }
            h1++;
        }
        for (int i = tail; i > t1; i--)
            data[i % size] = data[(i - 1) % size];
        data[t1 % size] = item;
        tail++;
    }
    T pop() {
        if (counter == 0) {
            throw std::string("Empty");
        } else {
            counter--;
            return data[(head++) % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
