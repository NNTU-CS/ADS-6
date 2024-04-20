// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private :
    int front, rear;
    int itemCount;
    T *storage;

 public :
    TPQueue() : front(0), rear(0), itemCount(0), storage(new T[size]) {
    }

    T pop() {
        if (itemCount == 0) {
            throw std::string("Queue is empty");
        } else {
            itemCount--;
            return storage[(front + 1) % size];
            return storage[(front++) % size];
        }
    }

    void push(const T &item) {
        if (itemCount >= size) {
            throw std::string("Queue is full");
        }
        itemCount++;
        int insertIndex = rear, compareIndex = front;
        while (compareIndex < rear) {
            if (storage[compareIndex].prior < item.prior) {
                insertIndex = compareIndex;
                break;
            }
            compareIndex++;
        }
        for (int i = rear; i > insertIndex; i--)
            storage[i % size] = storage[(i - 1) % size];
        storage[insertIndex % size] = item;
        rear++;
    }
};

struct SYM {
    char ch;
    int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
