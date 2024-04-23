// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int size>
class TPQueue {
private:
    T *inform;
    int start, end, k;
public:
    TPQueue() : start(0), end(0), k(0) { inform = new T[size]; }

    void push(const T &m) {
        if (k >= size) {
            throw std::string("full queue");
        }
        k++;
        int fl = end;
        for (int item = start; item < end; item++) {
            if (inform[item].prior < m.prior) {
                fl = item;
                break;
            }
        }
        for (int i = end - 1; i > fl + 1; i--) {
            inform[(i + 1) % size] = inform[i % size];
        }

        inform[fl % size] = m;
        end++;
    }

    T pop() {
        if (k == 0) {
            throw std::string("empty");
        } else {
            k--;
            return inform[start++ % size];
        }
    }
};


struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
