// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>
template<typename T, int size>
class TPQueue {
private:
    T* arr;
    int maxSize;
    int currentSize;

public:
    TPQueue() {
        arr = new T[size];
        maxSize = size;
        currentSize = 0;
    }

    ~TPQueue() {
        delete[] arr;
    }

    void push(const T& item, int priority) {
        if (currentSize < maxSize) {
            int i = currentSize - 1;
            while (i >= 0 && priority > arr[i].prior) {
                arr[i + 1] = arr[i];
                i--;
            }
            arr[i + 1] = item;
            currentSize++;
        }
        else {
            std::cout << "Queue is full" << std::endl;
        }
    }

    T pop() {
        if (currentSize > 0) {
            T item = arr[0];
            for (int i = 0; i < currentSize - 1; i++) {
                arr[i] = arr[i+1];
            }
            currentSize--;
            return item;
        }
        else {
            std::cout << "Queue is empty" << std::endl;
            return T();
        }
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == maxSize;
    }
};

struct SYM
{
	char ch;
	int  prior;
};
#endif  // INCLUDE_TPQUEUE_H_
