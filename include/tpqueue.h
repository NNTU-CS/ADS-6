// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
};
 private:
    T* arr;
    int begin, end, count;

 public:
    TPQueue() {
        begin = 0;
        end = 0;
        count = 0;
        arr = new T[size];
    }
    ~TPQueue() {
        delete[] arr;
    }
    void push(const T& item) {
        assert(count < size);
        count++;
        int pe = end;
        for (int i = begin; i < end; i++) {
            if (arr[i].prior < item.prior) {
                pe = i;
                break;
            }
        }
        for (int i = end - 1; i >= pe; i--) {
            arr[(i+1) % size] = arr[i % size];
        }
        arr[pe % size] = item;
        end++;
    }
    T pop() {
        assert(count > 0);
        count--;
        return arr[begin++ % size];
    }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
