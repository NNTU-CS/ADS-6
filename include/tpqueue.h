// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T *arr;
    int top, end;
    int c;

 public:
    TPQueue() : arr(new T[size]), top(0), end(0), c(0) {}
    void push(const T &i) {
        int i;
        if (c >= size) {
            throw std::string("Is full");
        } else {
            if (c == 0) {
                arr[top] = i;
                c++;
            } else {
                for (i = end; i >= top; i--) {
                    if (i.prior > arr[i % size].prior) {
                        arr[(i + 1) % size] = arr[i % size];
                    } else {
                        break;
                    }
                }
                end++;
                arr[(i + 1) %size] = i;
                c++;
            }
        }
    }
    T pop() {
        if (c == 0) {
            throw std::string("Is empty");
        } else {
            c--;
            return arr[top++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
