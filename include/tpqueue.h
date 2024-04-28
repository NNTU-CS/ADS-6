// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
private:
  T data[100] = {};
  int ind = 0, str = 0;

 public:
  T pop() {
    str += 1;
    return data[str - 1];
  }

  void push(T el) {
    data[ind] = el;
    ind += 1;
    for (int l = str; l < ind; l++) {
      for (int i = str; i < ind - 1; i++) {
        if (data[i + 1].prior > data[i].prior) {
          T k = data[i];
          data[i] = data[i + 1];
          data[i + 1] = k;
        }
      }
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
