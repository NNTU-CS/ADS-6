#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int size>
class TPQueue {
 private:
    int nachalo, konec, counter;
    T *data;

 public:
    TPQueue() : nachalo(0), konec(0), counter(0), data(new T[size]) {}

    T pop() {
        if (counter == 0) {
            throw std::string("Empty!!!");
        } else {
            counter--;
            return data[nachalo++ % size];
        }
    }

    void push(const T &item) {
        if (counter >= size)
            throw std::string("Full!!!");
        counter++;
        int Index = konec;
        for (int y = nachalo; y < konec; y++) {
            if (data[i].prior < item.prior) {
                Index = i;
                break;
            }
        }
        for (int y = konec; y > Index; y--)
            data[y % size] = data[(y - 1) % size];
        data[Index % size] = item;
        konec++;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
