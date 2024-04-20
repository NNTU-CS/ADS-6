// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>

struct SYM {
    char ch;
    int prior;
};

template<typename T, int size>
class TPQueue {
 private :
    T *arr;
    int begin, end;
    int count;

 public :
    TPQueue() : arr(new T[size]), begin(0), end(0), count(0) {
    }

    ~TPQueue() { delete[] arr; }

    void push(const T &item);

    T pop();

    void print() const;
};

template<typename T, int size>
void TPQueue<T, size>::push(const T &item) {
    if (count < size) {
        int i = end - 1;
        while (i >= begin && item.prior > arr[i].prior) {
            arr[(i + 1) % size] = arr[i];
            --i;
        }
        arr[(i + 1) % size] = item;
        ++end;
        if (end == size) end = 0;
        ++count;
    } else {
        std::cerr << "Queue is full!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

template<typename T, int size>
T TPQueue<T, size>::pop() {
    if (count > 0) {
        T highestPriorityItem = arr[begin];
        int highestPriorityIndex = begin;

        for (int i = begin + 1; i != (end == 0 ? size : end); ++i) {
            if (arr[i % size].prior < highestPriorityItem.prior) {
                highestPriorityItem = arr[i % size];
                highestPriorityIndex = i % size;
            }
        }

        for (int i = highestPriorityIndex;
             i != (end == 0 ? size - 1 : end - 1); ++i) {
            arr[i % size] = arr[(i + 1) % size];
        }
        --end;
        if (end < 0)
            end = size - 1;

        --count;

        return highestPriorityItem;
    } else {
        std::cerr << "Queue is empty!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

template<typename T, int size>
void TPQueue<T, size>::print() const {
    int i = begin;
    while (i != end) {
        std::cout << arr[i].ch << " ";
        ++i;
        if (i == size) i = 0;
    }
    std::cout << std::endl;
}
#endif  // INCLUDE_TPQUEUE_H_
