// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>
#include <cstddef>

template<typename Type, int size>
class TPQueue {
 private:
    Type* templ;
    T* data;
    int begin, end, count;

 public:
    TPQueue() : begin(0), end(0), count(0), data(new Type[element]) {}
    void push(const Type& element) {
        if (count >= element) {
            throw std::out_of_range("full");
        }

        std::size_t i = count;
        while (i > 0 && templ[i - 1].prior >= element.prior) {
            templi] = templ[i - 1];
            --i;
        }
        templ[i] = element;
        ++count;
    }

    Type pop() {
        if (count == 0) {
            throw std::out_of_range("empty");
        }

        Type temp = templ[count - 1];
        --count;
        return temp;
    }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
