// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    SYM* arr;
    int begin, end;
    int count;

 public:
    TPQueue() : count(0), begin(0), end(0) {
    arr = new SYM[size + 1];
    for (int i = 0; i < size; i++)
        arr[i] = { '-', 0 };
    }
    void push(SYM a) {
        if (!count) {
            arr[begin] = a;
            count++;
            end = begin;
        } else {
            int i = end;
            arr[i + 1] = a;
            while (i >= begin) {
                if (arr[i].prior < arr[i + 1].prior) {
                    SYM temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            i--;
            }
            end = end + 1;
            count++;
            }
    }

    SYM pop() {
        if (!count) {
            SYM a{ '0', -1 };
            return a;
        } else {
            SYM temp = arr[begin];
            for (int i = 0; i < count-1; i++) {
                arr[i] = arr[i + 1];
            }
            end--;
            count--;
            return temp;
        }
    }
    ~TPQueue() {
        delete []arr;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
