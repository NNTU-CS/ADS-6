// Cop// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
    T* arr;
    int count;

 public:
    TPQueue() : count(0), arr(new T[size]) {}
    ~TPQueue() {
        if (count >= 0) {
            delete[] arr;
        }
    }
    void push(const T& value) {
        int position = 0;
        while (position < count) {
            if (arr[position].prior < value.prior) break;
            position++;
        }
        T tmp1 = arr[position];
        arr[position] = value;
        for (int i = position + 1; i < count + 1; i++) {
            T tmp2 = arr[i];
            arr[i] = tmp1;
            tmp1 = tmp2;
        }
        count++;
    }
    T pop() {
        if (!count) throw std::string("Empty");
        T value = arr[0];
        count--;
        for (int i = 0; i < count; i++) {
            arr[i] = arr[i + 1];
        }
        return value;
    }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
