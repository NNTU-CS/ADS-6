// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int begin;
    int end;
    int count;

 public:
    TPQueue() : begin(0), end(0), count(0) {
        arr = new T[size];
    }

    ~TPQueue() {
        delete[] arr;
    }

void push(const T& item) {
        if (count >= size) {
            throw std::string("Full!!!");
        }

        int i;
        i = end - 1;

        while (i >= begin && arr[i % size].prior < item.prior) {
            arr[(i + 1) % size] = arr[i % size];
            i--;
        }

        arr[(i + 1) % size] = item;
        end++;
        count++;
    }

    T pop() {
        if (count > 0) {
            T item = arr[begin];
            begin = (begin + 1) % size;
            count--;
            return item;
        }
        throw "Queue is empty";
    }
};
struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
