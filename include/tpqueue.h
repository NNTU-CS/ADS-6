// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>
#include <cstddef>
template<typename Type, int size>
class TPQueue {
 private:
    Type* templ;
    std::size_t capacity;
    std::size_t count;

 public:
    TPQueue() : templ(new Type[size]), capacity(size), count(0) {}

    ~TPQueue() {
        delete[] templ;
    }

    void push(const Type& element) {
        if (count == capacity) {
            throw std::out_of_range("full");
        }

        std::size_t i = count;
        while (i > 0 && templ[i - 1].prior >= element.prior) {
            templ[i] = templ[i - 1];
            i--;
        }
        templ[i] = element;
        count++;
    }

    Type pop() {
        if (count == 0) {
            throw std::out_of_range("empty");
        }

        Type temp = templ[count - 1];
        count--;
        return temp;
    }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
