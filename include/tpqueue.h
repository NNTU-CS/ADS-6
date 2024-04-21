// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
    T arr[5];
    int k;

 public:
    TPQueue() : k(0), arr(new T[size]) {}
    ~TPQueue() {
        if (k >= 0) {
            delete[] arr;
        }
    }
    void push(const T& b) {
        int p = 0;
        while (p < k) {
            if (arr[p].prior < b.prior) break;
            p++;
        }
        T t1 = arr[p];
        arr[p] = b;
        for (int i = p + 1; i < k + 1; i++) {
            T t2 = arr[i];
            arr[i] = t1;
            t1 = t2;
        }
        k++;
    }
    T pop() {
        if (!k) throw std::string("Empty");
        T b = arr[0];
        k--;
        for (int i = 0; i < k; i++) {
            arr[i] = arr[i + 1];
        }
        return b;
    }
};
struct SYM
{
	char ch;
	int  prior;
};
#endif  // INCLUDE_TPQUEUE_H_
