// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int Size>
class TPQueue {
 private :
    T data[Size];
    int front, rear, itemCount;

 public :
    TPQueue() : front(0), rear(0), itemCount(0) {
    }

    void push(const T &item) {
        int currentSum;
        if (itemCount >= Size) {
            throw std::string("Full");
        } else {
            if (itemCount == 0) {
                data[front] = item;
               itemCount++;
            } else {
                for (currentSum = rear; currentSum >= front; currentSum--) {
                    if (item.prior > data[currentSum % Size].prior) {
                        data[(currentSum + 1) % Size] = data[currentSum % Size];
                    } else {
                        break;
                    }
                }
                rear++;
                data[(currentSum + 1) % Size] = item;
                itemCount++;
            }
        }
    }

    T pop() {
        if (itemCount == 0) {
            throw std::string("Empty");
        } else {
            itemCount--;
            return data[front++ % Size];
        }
    }
};

struct SYM {
    char ch;
    int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
