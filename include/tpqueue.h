// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>
template <typename T, int size> 
class TPQueue {
private:
    T data[size];
    int count;
    int begin, end;
public:
    TPQueue() : count(0), begin(0), end(0) {}

    void push(const T& elem, int prior) {
        if (count < size) {
            int pos = end;
            while (pos > begin && prior > data[(pos-1) % size].prior) {
                data[pos % size] = data[(pos-1) % size];
                pos--;
            }
            data[pos % size] = elem;
            end = (end + 1) % size;
            count++;
        } else {
            throw std::out_of_range("queue is full");
        }
    }

    T pop() {
        if (!isEmpty()) {
            T elem = data[begin];
            begin = (begin + 1) % size;
            count--;
            return elem;
        } else {
            throw std::out_of_range("queue is empty");
        }
    }

    bool isEmpty() {
        return (count == 0);
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif // INCLUDE_TPQUEUE_H_
