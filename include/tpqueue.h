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
    TPQueue() {
        head = 0;
        tail = 0;
        count = 0;
        data = new T[size];
    }
    void push(const T &item) {
        if (count >= size)
            throw std::string("Full data");
        count++;
        int tl1 = tail, hd1 = head;
        while (hd1 < tail) {
            if (data[hd1].prior < item.prior) {
                tl1 = hd1;
                break;
            }
            hd1++;
        }
        for (int i = tail; i > tl1; i--)
            data[i % size] = data[(i - 1) % size];
        data[tl1 % size] = item;
        tail++;
    }
    T pop() {
        if (count == 0) {
            throw std::string("Empty data");
        } else {
            count--;
            return data[(head++) % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
