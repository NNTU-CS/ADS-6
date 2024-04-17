// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
};

template <typename T, int size>
class TPQueue {
    // реализация шаблона очереди с приоритетом на кольцевом буфере
private:
    int c;
    int begin, end;
  	SYM* arr;
public:
    TPQueue() : c(0), begin(0), end(0) {
        arr = new SYM[size + 1];
        for (int i = 0; i < size; i++) {
            arr[i] = { '!', 0 };
        }
    }
    ~TPQueue() {
        delete[] arr;
    }
    void push(SYM x) {
        if (!c) {
            arr[begin] = x;
            c++;
            end = begin;
        } else {
            int n = end;
            arr[n + 1] = x;
            while (n >= begin) {
                if (arr[n].prior < arr[n + 1].prior) {
                    SYM temp = arr[n];
                    arr[n] = arr[n + 1];
                    arr[n + 1] = temp;
                }
                n--;
            }
            end = end + 1;
            c++;
        }
    }
    SYM pop() {
        if (!c) {
            SYM x{ '0', -2 };
            return x;
        } else {
            SYM temp = arr[begin];
            for (int i = 0; i < c - 1; i++) {
                arr[i] = arr[i + 1];
            }
            c--;
            end--;
            return temp;
        }
    }
};

#endif  // INCLUDE_TPQUEUE_H_
