// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int Size>
class TPQueue {
 private:
    T data[Size];
    int begin, end, count;
 public:
    TPQueue() : begin(0), end(0), count(0) {}

    void push(const T &item) {
        int i;
        if (count >= Size) {
            throw std::string("Full");
        } else {
            if (count == 0) {
                data[begin] = item;
                count++;
            } else {
                for (i = end; i >= begin; i--) {
                    if (item.prior > data[i % Size].prior) {
                        data[(i + 1) % Size] = data[i % Size];
                    } else {
                        break;
                    }
                }
                end++;
                data[(i + 1) % Size] = item;
                count++;
            }
        }
    }

    T pop() {
        if (count == 0) {
            throw std::string("Empty");
        } else {
            count--;
            return data[begin++ % Size];
        }
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
