// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T, int size>
class TPQueue {
 private:
  T* arr;
  int begin, end, count;

 public:
  TPQueue() : begin(0), end(0), count(0) {
    arr = new T[size+1];
  }
  ~TPQueue() {
    delete[] arr;
  }
  void push(const T& item) {
    assert(count < size);
    arr[end++] = item;
    count++;
    int i = end;
    for (; i >= begin; i--) {
			   if (arr[i].prior < item.prior)
				    arr[i + 1] = arr[i];
			   else
				    break;
		  }
		  arr[i + 1] = item;
		  end++;
  }
  T pop() {
    assert(count > 0);
    T item = arr[begin++];
    count--;
    return item;
  }
  T get() const {
    assert(count > 0);
    return arr[begin];
  }
  bool isEmpty() const {
    return count == 0;
  }
  bool isFull() const {
    return count == size;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
