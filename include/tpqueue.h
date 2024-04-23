// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int Size>
class TPQueue {
private:
    T inform[Size];
    int nach, end, k;

public:
    TPQueue() : nach(0), end(0), k(0) {}

    void push(const T &item) {
        int i;
        if (k >= Size) {
            throw std::string("full");
        } else {
            if (k == 0) {
                inform[nach] = item;
                k++;
            } else {
                for (i = end; i >= nach; i--) {
                    if (item.prior > inform[i % Size].prior) {
                        inform[(i + 1) % Size] = inform[i % Size];
                    } else {
                        break;
                    }
                }
                end++;
                inform[(i + 1) % Size] = item;
                k++;
            }
        }
    }

    T pop() {
        if (k == 0) {
            throw std::string("empty");
        } else {
            k--;
            return inform[nach++ % Size];
        }
    }
};

struct SYM {
    char ch;
    int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
