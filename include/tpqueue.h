// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    SYM* arr;
    int size, begin, end, k;

public:
    TPQueue(int s) : size(s), begin(0), end(0), k(0) {
        arr = new SYM[size];
    }

    ~TPQueue() {
        delete[] arr;
    }

    void push(SYM elem) {
        if (k < size) {
            int i = end - 1;
            while (i >= begin && elem.prior > arr[i].prior) {
                arr[i + 1] = arr[i];
                i--;
            }
            arr[i + 1] = elem;
            end++;
            k++;
        }
    }

    SYM pop() {
        if (k > 0) {
            k--;
            return arr[begin++];
        }
    }

    bool isEmpty() {
        return k == 0;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
