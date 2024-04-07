// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>
#include <vector>

struct SYM {
    char ch;
    int prior;
};

template <class T>
class TPQueue {
    private:
        std::vector<T> arr;
        int count;
    public:
        TPQueue() : count(0) {}
        void push(const T& elem) {
            if (arr.empty()) {
                arr.push_back(elem);
            } else {
                int i = arr.size() - 1;
                while (i >= 0 && elem.prior > arr[i].prior) {
                    arr[i + 1] = arr[i];
                    i--;
                }
                arr[i + 1] = elem;
            }
            count++;
        }
    T pop() {
        if (!arr.empty()) {
            T elem = arr.back();
            arr.pop_back();
            count--;
            return elem;
        } else {
            std::cerr << "Queue is empty." << std::endl;
            return T();
        }
    }
    bool isEmpty() const {
        return arr.empty();
    }
    int size() const {
        return count;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
