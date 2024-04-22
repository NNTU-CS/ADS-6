// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int last, first, count;

 public:
    TPQueue() : last(0), first(0), count(0) {
        arr = new T[size];
    }
    bool isEmpty() const {
        return 0 == count;
    }
    bool isFull() const {
        return count == size;
    }
    void push(const T& value) {
        if (isFull()) {
            throw std::string("Full");
        } else {
            int i = first;
            int j = first;
            while (value.prior > arr[i].prior) {
                if (value.prior < arr[i].prior) {
                    j = i;
                }
                i++;
            }
            for (int i = last; i > j; i--) {
                arr[i % size] = arr[(i - 1) % size];
            }
            arr[j % size] = value;
        }
        count++;
        last++;
    }
    const T& pop() {
        if (isEmpty()) {
            throw std::string("Empty");
        } else {
            --count;
            return arr[first++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
