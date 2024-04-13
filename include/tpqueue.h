// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* data;
    int counter, begin, end;

 public:
    TPQueue() : data(new T[size]), begin(0), end(0), counter(0) {}

    bool isFull() const {
        return counter == size;
    }

    bool isEmpty() const {
        return counter == 0 || (counter >= size);
    }

    T pop() {
        if (isEmpty()) {
            throw std::string("Empty!!!");
        } else {
            counter--;
            return data[begin % size];
            begin++;
        }
    }

    void push(const T& item) {
        if (isFull())
            throw std::string("Full!!!");
        counter++;
        int Indx = end;
        for (int i = begin; i < end; i++) {
            if (data[i].prior < item.prior) {
                Indx = i;
                break;
            }
        }
        for (int j = end; j > Indx; j--)
            data[j % size] = data[(j - 1) % size];
        data[Indx % size] = item;
        end++;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
