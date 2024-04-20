// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
struct SYM {
  char ch;
  int prior;
};
template<typename T, int size>
class TPQueue {
T* queue;
int current;
 public:
  TPQueue() {
    queue = new T[size];
    current = 0;
  }
  void push(T elm) {
    SYM temp = (SYM)elm;
    if (current == 0) {
      queue[0] = elm;
      current++;
    } else {
      queue[current++] = elm;
    }
  }
  T pop() {
    if (current == 0) {
      return T();
    } else {
      return queue[--current];
    }
  }
};
#endif  // INCLUDE_TPQUEUE_H_
