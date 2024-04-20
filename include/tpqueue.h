// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>
template<typename T, int size>
class TPQueue {
private:
 T data[size];
 int count;
 int begin;
 int end;
public:
 TPQueue () : count(0), begin(0), end(0) {}

 void push(const T& elem) { 
    if (count < size) {
        int pos = end;
        while (pos != begin && elem > data[(pos - 1 + size) % size]) {
            data[pos % size] = data[(pos - 1 + size) % size];
            pos = (pos - 1 + size) % size;
        }
        data[pos % size] = elem;
        end = (end + 1) % size;
        count ++;
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
            throw std::out_of_range("Queue is empty");
        }
    }

    bool isEmpty() {
        return (count == 0);
    }
};

struct SYM {
  char ch;
  int prior;

  bool operator>(const SYM& other) const {
    return prior > other.prior;
  }
};

#endif  // INCLUDE_TPQUEUE_H_
