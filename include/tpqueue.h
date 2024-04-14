// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

struct SYM {
    char ch;
    int prior;
};

template<typename T, int size>
class TPQueue {
 private:
    SYM* arr;
    int count;

 public:
    TPQueue() : count(0) {
        arr = new SYM[size + 1];
        for (int i = 0; i < size; ++i) {
            arr[i] = { ' ', 0 };
        }
    }

    void push(SYM a) {
        if (count >= size) {
            throw std::string("Full!");
        }
        int cur_ind = count;
        while (cur_ind != 0 && arr[cur_ind - 1].prior < a.prior) {
            arr[cur_ind] = arr[cur_ind - 1];
            cur_ind--;
        }
        arr[cur_ind] = a;
        count++;
    }

    SYM pop() {
        if (count == 0) {
            throw std::string("empty!");
        }
        SYM res = arr[0];
        for (int i = 0; i < count - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        count--;
        return res;
    }

    ~TPQueue() {
        delete[]arr;
    }
};
#endif  // INCLUDE_TPQUEUE_H_
