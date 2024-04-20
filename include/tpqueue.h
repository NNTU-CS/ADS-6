// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>

template<typename T, int size>
struct SYM {
    char ch;
    int prior;
};

class TPQueue {
 private:
    SYM* queue;
    int size;
    int capacity;
    int front;
    int rear;

 public:
    TPQueue(int capacity) {
        this->capacity = capacity;
        queue = new SYM[capacity];
        size = 0;
        front = 0;
        rear = -1;
    }

    ~TPQueue() {
        delete[] queue;
    }

    void push(SYM item) {
        if (size == capacity) {
            std::cout << "Queue is full, cannot enqueue more items." << std::endl;
            return;
        }
        int i;
        for (i = size - 1; i >= 0; i--) {
            if (queue[i].prior < item.prior) {
                queue[i + 1] = queue[i];
            } else {
                break;
            }
        }
        queue[i + 1] = item;
        size++;
    }

    SYM pop() {
        if (size == 0) {
            std::cout << "Queue is empty, cannot dequeue more items." << std::endl;
            exit(1);
        }
        SYM item = queue[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
