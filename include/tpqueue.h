// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>
template<typename T, int size>
class TPQueue {
private:
    T* dete;
    int begin, end, count;
public:
    TPQueue(): begin(0), end(0), count(0), dete(new T[size]) {}
void pus(const T& item) {
    if (count >= size) {
        throw std::string("Queue is full");
        } else {
            count++;
            int pos = end;
            int i = begin;
            while (i < end) {
                if (dete[i].prior < item.prior) {
                    pos = i;
                    break;
                }
                i++;
            }
            for (int i = end; i > pos; i--) {
                dete[(i % size)] = dete[((i - 1) % size)];
            }
            dete[(pos % size)] = item;
            end++;
        }
    }
    T pop() {
        if (count == 0) {
            throw std::string("Queue is empty");
        } else {
            count--;
            return dete[(begin++) % size];
        }
    }
};
struct SYM {
    char ch;
    int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
