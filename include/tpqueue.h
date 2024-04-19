// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, const int size>
class TPQueue {
  T arr[5];
  int k = 0;
  int end = 0;

 public:
  TPQueue() {
    for (int i = 0; i < size; i++) {
      arr[i].ch = 0;
      arr[i].prior = -10;
    }
  }
  void push(T sym) {
    if (end != 0) {
      int i = end - 1;
      for (; i >= k; i--) {
        if (sym.prior > arr[i].prior) {
          arr[i + 1] = arr[i];
        } else {
          break;
        }
      }
      arr[++i] = sym;
      end++;
    } else {
      arr[0] = sym;
      end++;
    }
  }
  T pop() {
    T f = arr[0];
    for (int i = k; i < end - 1; i++) {
      arr[i] = arr[i + 1];
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
