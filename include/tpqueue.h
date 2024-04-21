// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, const int size>
class TPQueue {
  struct Item {
    T data;
    int prior;
  };
  Item arr[size];
  int m = 0, end = 0;

 public:
  TPQueue() {
    for (int i = 0; i < size; i++) {
      arr[i].data = T();
      arr[i].prior = -10;
    }
  }
  void push(T sym, int priority) {
    if (end != 0) {
      int i = end - 1;
      for (; i >= m; i--) {
        if (priority > arr[i].prior) {
          arr[i + 1].data = arr[i].data;
          arr[i + 1].prior = arr[i].prior;
        } else {
          break;
        }
      }
      arr[++i].data = sym;
      arr[i].prior = priority;
      end++;
    } else {
      arr[0].data = sym;
      arr[0].prior = priority;
      end++;
    }
  }
  T pop() {
    T f = arr[m].data;
    for (int i = m; i < end - 1; i++) {
      arr[i].data = arr[i + 1].data;
      arr[i].prior = arr[i + 1].prior;
    }
    end--;
    return f;
  }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
