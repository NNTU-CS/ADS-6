// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    SYM* arr;
    int kolvo;
    int top, c;

  public:
    TPQueue() : kolvo(0), top(0), c(0) {
        arr = new SYM[size + 1];
        for (int i = 0; i < size; i++) 
            arr[i] = {'-', 0};
    }
    void push(SYM bb) {
        if (!kolvo) {
            arr[top] = bb;
            kolvo++;
            c = top;
        } else {
            int i = c;
            arr[i + 1] = bb;
            while (i >= top) {
                if (arr[i].prior < arr[i + 1].prior) 
                    SYM t = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = t;
                i--;
            }
            c = c + 1;
            kolvo++;
        }
    }
    SYM pop() {
        if (!kolvo) {
            SYM bb{'0', -1};
            return bb;
        } else {
            SYM t = arr[top];
            for (int i = 0; i < kolvo - 1; i++) {
                arr[i] = arr[i + 1];
            }
            c--;
            kolvo--;
            return t;
        }
    }
    ~TPQueue() { 
     delete[] arr;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
