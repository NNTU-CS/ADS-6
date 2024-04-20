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
    TPQueue();

    ~TPQueue();

    void push(const T &item);

    T pop();

    void print() const;
};

template<typename T, int size>
TPQueue<T, size>::TPQueue() : arr(new T[size]), begin(0), end(0), count(0) {
}

template<typename T, int size>
TPQueue<T, size>::~TPQueue() {
    delete[] arr;
}

template<typename T, int size>
void TPQueue<T, size>::push(const T &item) {
    if (count < size) {
        arr[end++] = item;
        ++count;
        if (end == size)
            end = 0;
        for (int i = begin; i < end - 1; ++i) {
            for (int j = begin; j < end - 1; ++j) {
                if (arr[j].prior > arr[j + 1].prior) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
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

        // Найти элемент с наивысшим приоритетом
        for (int i = begin + 1; i != end; ++i) {
            if (arr[i].prior < highestPriorityItem.prior) {
                highestPriorityItem = arr[i];
                highestPriorityIndex = i;
            }
        }

        // Удалить элемент с наивысшим приоритетом из очереди
        for (int i = highestPriorityIndex; i != end - 1; ++i) {
            arr[i] = arr[i + 1];
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
    for (int i = begin; i < end; ++i) {
        std::cout << arr[i].ch << " ";
    }
    std::cout << std::endl;
}
#endif  // INCLUDE_TPQUEUE_H_
