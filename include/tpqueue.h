// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

template<typename T, int size>
class TPQueue {
 private:
    struct QueueItem {
        T data;
        int prior;
    };

    QueueItem queue[size];
    int begin, end, count;

 public:
    TPQueue() : begin(0), end(0), count(0) {}

    void push(const T& item) {
        if (count >= size) {
            throw std::out_of_range("Queue is full");
        }
        if (count == 0) {
            queue[end].data = item;
            queue[end].prior = item.prior;
            count++;
            return;
        }
        int current = end;
        while (current != begin && item.prior > queue[(current - 1 + size) % size].prior) {
            queue[current] = queue[(current - 1 + size) % size];
            current = (current - 1 + size) % size;
        }
        queue[current].data = item;
        queue[current].prior = item.prior;
        end = (end + 1) % size;
        count++;
    }

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        T result = queue[begin].data;
        begin = (begin + 1) % size;
        count--;
        return result;
    }

    bool isEmpty() const {
        return count == 0;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
