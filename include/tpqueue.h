// Copyright 2022 NNTU-CS
#include <string>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T, int size>
class TPQueue {
 private:
  T* array = new T[size];
  int currentElementWithMaxPrior = size;

 public:
  TPQueue() {
  for (int i = 0; i < size; i++) {
  array[i].prior = 1000;
  }
  }
  void push(T element) {
  T elementToPlace = element;
  currentElementWithMaxPrior--;
  for (int i = size-1; i >= 0; i--) {
    if (elementToPlace.prior <= array[i].prior) {
      T temp = elementToPlace;
      elementToPlace = array[i];
      array[i] = temp;
    }
  }
  }
  T pop() {
  if (currentElementWithMaxPrior == size)
    throw std::exception();
  T result = array[currentElementWithMaxPrior];
  array[currentElementWithMaxPrior].prior = 1000;
  currentElementWithMaxPrior++;
  return result;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
