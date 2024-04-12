// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
struct SYM {
  char ch;
  int prior;
};
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    SYM* arr;
    int star, tail;
    int zero;
 public:
    TPQueue() : star(0), tail(0), zero(0) {
        arr = new SYM[size + 1];
        for (int j = 0; j < size; j++)
            arr[j] = { '-', 0 };
    }
    void push(SYM b) {
        if (!zero) {
            arr[star] = b;
            zero++;
            tail = star;
        } else {
            int t = tail;
            arr[t + 1] = b;
            while (t >= star) {
                if (arr[t].prior < arr[t + 1].prior) {
                    SYM red = arr[t];
                    arr[t] = arr[t + 1];
                    arr[t + 1] = red;
                }
                t--;
            }
            zero++;
            tail = tail + 1;
        }
    }

    SYM pop() {
        if (!zero) {
            SYM u{ '0', -2 };
            return u;
        } else {
            SYM top = arr[star];
            for (int j = 0; j < zero - 1; j++) {
                arr[j] = arr[j + 1];
            }
            zero--;
            tail--;
            return top;
        }
    }
    ~TPQueue() {
        delete[]arr;
    }
};


#endif  // INCLUDE_TPQUEUE_H_
