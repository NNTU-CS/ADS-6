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
    SYM* arr;
    int begin, end;
    int cnt;

 public:
    TPQueue() : count(0), begin(0), end(0) {
    arr = new SYM[size + 1];
    for (int i = 0; i < size; i++)
        arr[i] = { '-', 0 };
    }
    void push(SYM a) {
        if (!count) {
            arr[begin] = a;
            cnt++;
            end = begin;
        } else {
            int i = end;
            arr[i + 1] = a;
            while (i >= begin) {
                if (arr[i].prior < arr[i + 1].prior) {
                    SYM tmp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = tmp;
                }
            i--;
            }
            end = end + 1;
            cnt++;
            }
    }

    SYM pop() {
        if (!cnt) {
            SYM a{ '0', -2 };
            return a;
        } else {
            SYM tmp = arr[begin];
            for (int i = 0; i < cnt-1; i++) {
                arr[i] = arr[i + 1];
            }
            end--;
            cnt--;
            return tmp;
        }
    }
    ~TPQueue() {
        delete []arr;
    }
};



#endif  // INCLUDE_TPQUEUE_H_
