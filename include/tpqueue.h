// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>

template <typename T>
struct ITEM {
    T data;
    int prior;
};

template <typename T, int size>
class TPQueue {
 private:
    ITEM<T> queue[size];
    int begin, end;

 public:
    TPQueue() : begin(0), end(0) {}
    void push(const T& data, int prior) {
        int current = end;
        while (current != begin && prior > queue[current - 1].prior) {
            queue[current] = queue[current - 1];
            if (--current < 0) {
                current += size;
            }
        }
        queue[current].data = data;
        queue[current].prior = prior;
        end = (end + 1) % size;
    }
    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        if (--end < 0) {
            end += size;
        }
        return queue[end].data;
    }
    bool isEmpty() const {
        return begin == end;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
