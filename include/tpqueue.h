// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
class TPQueue {
  int Start, End, Quantity;
  T* arr;
public:
  TPQueue(){
    Start = 0;
    End = 0;
    Quantity = 0;
    arr = new T[size];
  }
  void push(const T& Instance) {
    if (Quantity == 0) {
      Quantity++;
      arr[0] = Instance;
    }
    int i = 0;
    else if (Quantity < size) {
      Quantity++;
      for (i = End; i >= Start; i--) {
        if (Instance.prior > arr[i].prior) {
          arr[(i + 1) % size] = arr[i % size];
        } else {
            break;
        }
      arr[(i + 1) % size] = Instance;
      End++;
    }
  }
  T pop() {
    Quantity--;
    return arr[(Start++) % size];
  }
};
#endif  // INCLUDE_TPQUEUE_H_
