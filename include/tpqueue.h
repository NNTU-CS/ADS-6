// Copyright 2022 NNTU-CS
#include <string>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
private:
    T *arr;
    int begin, end, count;

 public:
    TPQueue() : begin(0), end(0), count(0), arr(new T[size]) {}
    void push(const T& item) {
        if (count >=size)
            throw std::string("Full");
        int index = end;
        count++;
        for (int i = begin; i < end; i++) {
            if (arr[i].prior < item.prior) {
                index = i;
                break;
            }
        }
        for (int i = end; i > index; i--) {
            arr[i % size] = arr[(i - 1) % size];
        }
        arr[index % size] = item;
        end++;
    }
    T pop() {
        if (count == 0) {
            throw std::string("Empty");
        } 
        else {
            count--;
            return arr[begin++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
