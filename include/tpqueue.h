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
    SYM* mas;
    int counter;
    int head, tail;

 public:
    TPQueue() : counter(0), head(0), tail(0) {
        mas = new SYM[size + 1];
        for (int j = 0; j < size; j++)
            mas[j] = { '-', 0 };
    }
    void push(SYM c) {
        if (!counter) {
            mas[head] = c;
            counter++;
            tail = head;
        } else {
            int j = tail;
            mas[j + 1] = c;
            while (j >= head) {
                if (mas[j].prior < mas[j + 1].prior) {
                    SYM mp = mas[j];
                    mas[j] = mas[j + 1];
                    mas[j + 1] = mp;
                }
                j--;
            }
            tail = tail + 1;
            counter++;
        }
    }

    SYM pop() {
        if (!counter) {
            SYM e{ '0', -2 };
            return e;
        } else {
            SYM mp = mas[head];
            for (int j = 0; j < counter - 1; j++) {
                mas[j] = mas[j + 1];
            }
            tail--;
            counter--;
            return mp;
        }
    }
    ~TPQueue() {
        delete[]mas;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
