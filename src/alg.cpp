// Copyright 2021 NNTU-CS
#pragma once

#include <iostream>

template <class T>
class TPQueue {
private:
    T* arr;
    int size;
    int begin, end;
    int count;

public:
    TPQueue(int s = 100) : size(s), begin(0), end(0), count(0) {
        arr = new T[size + 1];
    }

    ~TPQueue() {
        delete[] arr;
    }

    void push(const T& item) {
        if (count < size) {
            if (end != 0) {
                int i = end - 1;
                while (i >= begin) {
                    if (item.prior > arr[i].prior) {
                        arr[i + 1] = arr[i];
                        arr[i] = item;
                    } else
                        break;
                    i--;
                }
            } else {
                int i = size;
                while (i >= begin) {
                    if (item.prior > arr[i].prior) {
                        arr[i + 1] = arr[i];
                        arr[i] = item;
                    } else
                        break;
                    i--;
                }
            }
            end++;
            count++;
        }
    }

    T pop() {
        if (count > 0) {
            if (end > 0)
                end--;
            else
                end = size;
            count--;
            return arr[end];
        }
        return T();
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == size;
    }
};
