#ifndef TPQUEUE_H
#define TPQUEUE_H

#include <iostream>


struct SYM {
    char ch;
    int prior;
};


template <typename T>
class TPQueue {
private:
    T* arr;
    int size;
    int begin;
    int end;
    int count;

public:
    TPQueue(int = 100);
    ~TPQueue();

    void push(const T&);
    T pop();
    T get() const;
    bool isEmpty() const;
    bool isFull() const;

    void print() const;
};

template <typename T>
TPQueue<T>::TPQueue(int sizeQueue) :
        size(sizeQueue),
        begin(0), end(0), count(0) {
    arr = new T[size + 1];
}

template <typename T>
TPQueue<T>::~TPQueue() {
    delete[] arr;
}

template <typename T>
void TPQueue<T>::push(const T& item) {

    if (isFull()) {
        throw std::logic_error("Queue is full");
    }

    if (isEmpty()) {
        arr[begin] = item;
    } else {
        int i = end - 1;

        while (i >= begin && arr[i].prior < item.prior) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = item;
    }

    count++;

    end = (end + 1) % size;
}

template <typename T>
T TPQueue<T>::pop() {

    if (isEmpty()) {
        throw std::logic_error("Queue is empty");
    }

    T item = arr[begin];

    count--;

    begin = (begin + 1) % size;
    return item;
}

template <typename T>
T TPQueue<T>::get() const {

    if (isEmpty()) {
        throw std::logic_error("Queue is empty");
    }

    return arr[begin];
}

template <typename T>
bool TPQueue<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
bool TPQueue<T>::isFull() const {
    return count == size;
}

template <typename T>
void TPQueue<T>::print() const {

    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    int i = begin;
    while (i != end) {
        std::cout << "ch: " << arr[i].ch << ", prior: " << arr[i].prior << std::endl;
        i = (i + 1) % size;
    }
}

#endif // TPQUEUE_H
