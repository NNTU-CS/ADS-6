// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int size>
class TPQueue {
  public:
     TPQueue() : b(0), e(0), count(0) {}

    void push(const T& elem) {
        int i;
        if (count > size) {
            throw std::string("full");
        } else {
            if (count == 0) {
                MyData[b] = elem;
                count++;
            } else {
                for (i = e; i >= b; i--) {
                    if (elem.priority > MyData[i % size].priority) {
                        MyData[(i + 1) % size] = MyData[i % size];
                    } else {
                        break;
                    }
                }
                e++;
                MyData[(i + 1) % size] = elem;
                count++;
            }
        }
    }

    T pop() {
        if (count == 0) {
            throw std::string("empty");
        } else {
            count--;
            return MyData[b++ % size];
        }
    }
  private:
    T MyData[size];
    int b, e, count;
};
 struct SYM {
    char ch;
    int priority;
  };
#endif  // INCLUDE_TPQUEUE_H_
