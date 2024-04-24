// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
private:
  T* arr;
  int size, begin, end, count;

public:
  TQueue(int = 100);
  ~TQueue();
  void push(const T&);
  T pop();
  T get() const;
  bool isEmpty() const;
  bool isFull() const;
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
