// include/tpqueue.h
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* data;
    int head, tail, counter;  // изменение имен переменных

 public:
    TPQueue() : head(0), tail(0), counter(0), data(new T[size]) {}

    ~TPQueue() {
        delete[] data;
    }

    void push(const T& item) {  // изменение имени метода
        if (counter >= size) {
            throw std::string("Full");
        } else {
            counter++;
            int pos = tail, i = head;  // изменение имен переменных
            while (i < tail) {
                if (data[i].prior < item.prior) {
                    pos = i;
                    break;
                }
                i++;
            }
            for (int i = tail; i > pos; i--)
                data[i % size] = data[(i - 1) % size];
            data[pos % size] = item;
            tail++;
        }
    }

    T pop() {  // изменение имени метода
        if (counter == 0) {
            throw std::string("Empty");
        } else {
            counter--;
            return data[(head++) % size];
        }
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
