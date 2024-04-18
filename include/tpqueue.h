// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T *data;
    int begin, end, counter;

 public:
    TPQueue(): data(new T[size]), begin(0), end(0), counter(0) {}
    void push(const T &item) {
        int i;
        if (counter >= size) {
            throw std::string("Full!");
        } else {
            if (counter == 0) {
                data[begin] = item;
                counter++;
            } else {
                for (i = end; i >= begin; i--) {
                    if (item.prior > data[i % size].prior) {
                        data[(i + 1) % size] = data[i % size];
                    } else {
                        break;
                    }
                }
                end++;
                data[(i + 1) % size] = item;
                counter++;
            }
        }
    }
    T pop() {
        if (counter == 0) {
            throw std::string("Empty!");
        } else {
            counter--;
            return data[begin++ % size];
        }
    }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
