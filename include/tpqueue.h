// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T, int size>
class TPQueue {
 private:
  int end, begin, count;
  T* a;

 public:
  TPQueue() : a(new T[size]), begin(0), end(0), count(0) {}
  void push(const T& t) {
    count++;
    int p = end;
    for (int i = end; i >= begin; i--) {
      if (t.prior > a[i].prior) {
        p = i;
        break;
      }
    }
    for (int i = end; i > p; i--) a[i % size] = a[(i - 1) % size];
    a[p % size] = t;
    end++;
  }
  T& pop() {
    if (count != 0) {
      count--;
      return a[begin++ % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
