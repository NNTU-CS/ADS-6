// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
private:
    int begin, end, count;
    T data [size];
public:
     TPQueue() :begin(0), end(0), count(0) {}
    void push(const T & item) {
       int i = end;
       count = 1;
       data[begin] = item;
       if (count >= size)
           throw std::string("is full");
   else {
       for (i = end; i >= begin; i--) {
        if (item.prior > data[i % size].prior) {
            data[(i + 1) % size] = data[i % size];
        }
        else break;
     }
        data[(i + 1) % size] = item;
        end++;
        count++;
           }
       }
    T pop() {
        if (count == 0) {
            throw std::string("is empty");
        }
        else {
            count--;
            return data[(begin++) % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
