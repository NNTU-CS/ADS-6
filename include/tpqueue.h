// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
private:
    int begin, end, count;
    T data [size];
public:
    TPQueue() :begin(0), end(0), count(0) {}
    void push(T item) {
        int prior = item.prior, i = end;
        if (count >= size)
            throw std::string("is full");
        else {
            for (; i >= begin; i--) {
                if (data[i].prior < prior) {
                    data[i + 1] = data[i];
                }
                else break;
            }
            data[i + 1] = item;
            end++;
            count++;
        }
    }
    T pop() {
        if (count == 0) {
            throw std::string("is empty");
        }
        else {
            count--;
            return data[begin++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
