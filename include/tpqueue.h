// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

template<typename T, int size>
class TPQueue {
 private :
    int head, tail;
    int count;
    T *data;

 public :
    TPQueue() : head(0), tail(0), count(0), data(new T[size]) {
    }

    T pop() {
        if (count == 0) {
            throw std::out_of_range("Queue is empty");
        } else {
            int highest_priority_index = head;
            for (int i = head + 1; i < tail; ++i) {
                if (data[i % size].prior <
                    data[highest_priority_index % size].prior) {
                    highest_priority_index = i;
                }
            }
            T highest_priority_item = data[highest_priority_index % size];

            for (int i = highest_priority_index; i < tail - 1; ++i) {
                data[i % size] = data[(i + 1) % size];
            }

            --tail;
            --count;

            return highest_priority_item;
        }
    }

    void push(const T &item) {
        if (count >= size) {
            throw std::out_of_range("Queue is full");
        }

        int insert_index = tail;
        while (insert_index > head && data[(insert_index - 1) % size].prior > item.prior) {
            data[insert_index % size] = data[(insert_index - 1) % size];
            --insert_index;
        }

        data[insert_index % size] = item;
        ++tail;
        ++count;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
