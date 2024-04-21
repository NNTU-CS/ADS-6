// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* data;
    int startPoint, endPoint, counter;

 public:
    TPQueue() : data(new T[size]), startPoint(0), endPoint(0), counter(0) {}

    void push(const T &item) {
        int intznach;
        if (counter >= size) {
            throw std::string("Full slots");
        } else {
            if (counter == 0) {
                data[startPoint] = item;
                counter++;
            } else {
                for (intznach = endPoint; intznach >= startPoint; intznach--) {
                    if (item.prior > data[intznach % size].prior) {
                        data[(intznach + 1) % size] = data[intznach % size];
                    } else {
                        break;
                    }
                }
                endPoint++;
                data[(intznach + 1) % size] = item;
                counter++;
            }
        }
    }
    T pop() {
        if (counter == 0) {
            throw std::string("Empty slots");
        } else {
            counter--;
            return data[startPoint++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
