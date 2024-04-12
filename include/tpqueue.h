// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T, int size>
class TPQueue {
 private:
  int end = 0, begin = 0, count;
  T* arr;

 public:
  TPQueue() : arr(new T[size]), begin(0), end(0), count(0) {}
  void push(const T& value) {
    int i;
    for (i = end; i >= begin; i--) {
      if (value.prior > arr[i].prior)
        arr[i + 1] = arr[i];
      else
        break;
    }

    arr[i + 1] = value;
    end++;
  }
  T& pop() {
    end--;
    return arr[begin++ % size];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
