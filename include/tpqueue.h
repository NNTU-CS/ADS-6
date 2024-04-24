// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T inform[size];
    int nach, end, k;

 public:
    TPQueue() : nach(0), end(0), k(0) {}

    void push(const T &item) {
        int i;
        if (k >= size) {
            throw std::string("full");
        } else {
            if (k == 0) {
                inform[nach] = item;
                k++;
            } else {
                for (i = end; i >= nach; i--) {
                    if (item.prior > inform[i % size].prior) {
                        inform[(i + 1) % size] = inform[i % size];
                    } else {
                        break;
                    }
                }
                end++;
                inform[(i + 1) % size] = item;
                k++;
            }
        }
    }

    T pop() {
        if (k == 0) {
            throw std::string("empty");
        } else {
            k--;
            return inform[nach++ % size];
        }
    }
};

struct SYM {
    char ch;
    int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
