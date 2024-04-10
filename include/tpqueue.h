// Copyright 2024 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>

struct SYM {
    char ch;
    int prior;
};

template <typename F, int size>
class TQueue {
 private:
     SYM* a;
     int begin, end;
     int cnt;

 public:
     TQueue() : begin(0), end(0), cnt(0) {
         a = new SYM[size + 1];
         for (int j = 0; j < size; j++)
             a[j] = { '--', 0 };
     }
     void push(SYM qwerty) {
         if (cnt == 0) {
             a[begin] = qwerty;
             cnt++;
             end = begin;
         } else {
             int k = end;
             a[k + 1] = qwerty;
             while (k + 1 > begin) {
                 if (a[k].prior < a[k + 1].prior) {
                     SYM tmp = a[k].prior;
                     a[k].prior = a[k+1].prior;
                     a[k + 1].prior = tmp;
                 }
             i--;
             }
             end += 1;
             cnt++;
         }
     }
     SYM pop() {
         if (cnt == 0) {
             SYM qwerty{ '0', -2 };
             return qwerty;
         } else {
             SYM tmp = a[begin];
             for (int k = 0; k < cnt - 1; ++k) {
                 a[k] = a[k + 1];
             }
             end--;
             cnt--;
             return tmp;
         }
     }
     ~TQueue() {
         delete [] a;
     }
};

#endif  // INCLUDE_TPQUEUE_H_
