// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[5];
    int c, e;

 public:
    TPQueue() {
        for (int i = 0; i < size; i++) {
            arr[i].ch = 0;
            arr[i].prior = -10;
        }
    }
    void push(T sym) {
        if (e != 0) {
                int i = e - 1;
                for (; i >= c; i--) {
                    if (sym.prior > arr[i].prior) {
                        arr[i + 1] = arr[i];
                    } else {
                        break;
                    }
                }
                arr[++i] = sym;
                e++;
            } else {
                arr[0] = sym;
                e++;
            }
        }
        T pop() {
            T temp = arr[0];
            for (int i = c; i < e - 1; i++) {
                arr[i] = arr[i + 1];
            }
            e--;
            return temp;
     }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
