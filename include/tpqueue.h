// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T *arr;
    int begin, end, count;

 public:
    TPQueue(): begin(0), end(0), count(0), arr(new T[size]) {}
    void push(const T& item) {
        int currentNumber;
        if (count >= size) {
            throw std::string("Full!!!");
        } else {
            if (count == 0) {
                arr[begin] = item;
            } else {
                for (currentNumber = end; currentNumber > begin; currentNumber--) {
                    if (item.prior > arr[currentNumber % size].prior) {
                        arr[(currentNumber++) % size] = arr[currentNumber % size];
                    } else {
                        break;
                    }
                }
                end++;
                arr[(currentNumber++) % size] = item;
            }
            count++;
        }
    }
    T pop() {
        if (count == 0) {
            throw std::string("Empty!");
        }
        else {
            count--;
            return arr[(begin++) % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
