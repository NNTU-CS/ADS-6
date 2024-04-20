// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
char ch;
int prior;
};

template<typename T, int size>
class TPQueue {
 private:
T* arr; 
int item; 
public:
 TPQueue() :  item(0), arr(new T[size]) {};
 ~TPQueue() { delete[] arr; };
 void push(const T&elm) {
  SYM temp = (SYM)elm;
  if (arr == 0) {
   item++;
  }
  else if (item != size) {
   int pos = 0;
   for (int i = item; i > 0; i--) {
    if (((SYM)arr[i - 1]).prior < temp.prior) {
     pos = i;
     break;
    }
    arr[i] = arr[i - 1];
   }
   arr[pos] = elm;
   item++;
  }
 }
 T pop() {
  if (item == 0) {
   return T();
  }
  else {
   return arr[--item];
  }
 }
};

#endif  // INCLUDE_TPQUEUE_H_
