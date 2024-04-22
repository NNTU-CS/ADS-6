// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T, int Size>

class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    T data[Size];
    int a, b, c;

 public:
    TPQueue() : a(0), b(0), c(0) {}

    void push(const T &ai) {
        int p;
        if (c >= Size) {
            throw std::string("Full");
        } else {
            if (c == 0) {
                data[a] = ai;
                c++;
            } else {
                for (p = b; p >= a; p--) {
                    if (ai.prior > data[p % Size].prior) {
                        data[(p + 1) % Size] = data[p % Size];
                    } else {
                        break;
                    }
                }
                b++;
                data[(p + 1) % Size] = ai;
                c++;
            }
        }
    }

    T pop() {
        if (c == 0) {
            throw std::string("Empty");
        } else {
            c--;
            return data[a++ % Size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_

