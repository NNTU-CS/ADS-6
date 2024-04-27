// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T *arr;
int head, tail, count;

 public:
    TPQueue():head(0), tail(0), count(0), arr(new T[size]) {}
    void push(const T& item) {
        if (count >=size) {
         throw std::string("queue is full");
        }
     int inx = tail;
     count++;
     for (int i = head; i < tail; i++) {
      if (arr[i].priority < item.priority) {
       inx = 1;
       break;
      }
     }
     for (int i = tail; i > inx; i--) {
      arr[inx % size] = arr[(i - 1) % size];
     }
     arr[inx % size] = item;
    }
    T pop() {
       if (count == 0) {
            throw std::string("queue is empty");
        } else {
        count--;
        return arr[head++ % size];
        }
    }
};

struct SYM {
    char ch;
    int priority;
};

#endif  // INCLUDE_TPQUEUE_H_
