// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T, int size>
class TPQueue {
 private:
    T* array;
    int begin, end, k;

 public:
    TPQueue() : begin(0), end(0), k(0) {
        array = new T[size];
    }

    ~TPQueue() {
        delete[] array;
    }

    void push(const T& el) {
         int ind = end;
         k++;
         if (k >= size)
            throw std::string("Queue is Full!");
         for (int i = begin; i < end; i++) {
            if (array[i].prior < el.prior) {
                ind = i;
                break;
            }
         }
         for (int i = end - 1; i >= ind; i--)
            array[(i + 1) % size] = array[i % size];
         array[ind % size] = el;
         end++;
    }

    T pop() {
        if (k == 0) {
            throw std::string("Queue is empty");
        } else {
            k--;
            return array[begin++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
