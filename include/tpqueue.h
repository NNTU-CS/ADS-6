// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {

private:
    T* arr;
    int count;
    int begin;
    int end;

public:
    TPQueue() : count(0), begin(0), end(0) {
        arr = new T[size + 1];
    ~TPQueue() {
        delete[] arr;
    }
    void insert(const T& item) {
        if (count == size) {
            throw "Queue is full";
        }
        int tmp = end - 1;
        if (tmp < 0) {
            tmp = size;
        }
        int itemPrior = item.prior;
        while (tmp >= begin && itemPrior > arr[tmp].prior) {
            arr[tmp + 1] = arr[tmp];
            tmp--;
        }
        arr[tmp + 1] = item;
        end++;
        if (end > size) {
            end = 0;
        }
        count++;
    }
    T get() {
        if (count == 0) {
            throw "Queue is empty";
        }
        T tmp = arr[begin];
        begin++;
        if (begin > size) {
            begin = 0;
        }
        count--;
        return tmp;
    }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
