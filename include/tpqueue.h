// Copyright 2022 NNTU-CS
#include <assert.h>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int sizeq;
    int begin, end;
    int count;

 public:
    TPQueue(): begin(0), end(0), count(0), sizeq(size) {
        arr = new T[sizeq + 1];
    }

    ~TPQueue() {
        delete[] arr;
    }

    void push(const T& item) {
        assert(count < sizeq);
        int i;
        if (count == 0) {
            arr[begin] = item;
        } else {
            for (i = end; i >= begin; i--) {
                if (item.prior > arr[i].prior)
                    arr[i + 1] = arr[i];
                else
                    break;
            }
            arr[i + 1] = item;
            end++;
        }
        count++;
        if (end > size)
            end -= size + 1;
    }

    T pop() {
        assert(count > 0);
        T item = arr[begin];
        begin++;
        count--;
        if (begin > sizeq)
            begin -= sizeq + 1;
        return item;
    }

    T get() const {
        assert(count > 0);
        return arr[begin];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
