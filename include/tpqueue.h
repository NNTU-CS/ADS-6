// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T *data;
    int begin, end, count;

 public:
    TPQueue() : data(new T[size]), begin(0), end(0), count(0) {}

    bool isFull() const {
        return (count == size) || (count >= size);
    }

    bool isEmpty() const {
        return count == 0;
    }

    T pop() {
        if (isEmpty()) {
            throw std::string("Queue is empty");
        } else {
            count--;
            T result = *(data + begin % size);
            begin++;
            return result;
        }
    }

    void push(const T &item) {
        int i;
        if (isFull()) {
            throw std::string("Queue is full");
        } else {
            if (count == 0) {
                data[begin] = item;
                count++;
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
                count++;
            }
        }
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
