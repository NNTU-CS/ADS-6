// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>

using namespace std;

template<typename T, int size>
class TPQueue {
private:
    T *arr;
    int begin, end;
    int count;
public:
    TPQueue();
    ~TPQueue();
    void push(const T &);
    T pop();
    T get() const;
    bool isEmpty() const;
    bool isFull() const;
    void print() const;
};

template<typename T, int size>
TPQueue<T, size>::TPQueue() :
    begin(0), end(0), count(0) {
    arr = new T[size + 1];
}

template<typename T, int size>
TPQueue<T, size>::~TPQueue() {
    delete [] arr;
}

template<typename T, int size>
void TPQueue<T, size>::push(const T & item) {
    if (!isFull()) {
        arr[end++] = item;
        count++;
        if (end > size) {
            end -= size + 1;
        }
    }
}

template<typename T, int size>
T TPQueue<T, size>::pop() {
    if (!isEmpty()) {
        count--;
        T item = arr[begin++];
        if (begin > size) {
            begin -= size + 1;
        }
        return item;
    }
}

template<typename T, int size>
T TPQueue<T, size>::get() const {
    return arr[begin];
}

template<typename T, int size>
bool TPQueue<T, size>::isEmpty() const {
    return count == 0;
}

template<typename T, int size>
bool TPQueue<T, size>::isFull() const {
    return count == size;
}

template<typename T, int size>
void TPQueue<T, size>::print() const {
    int b = begin;
    int cnt = count;
    while (cnt > 0) {
        cout << arr[b].ch << " ";
        if (b < size) {
            b++;
        } else {
            b = 0;
        }
        cnt--;
    }
    cout << endl;
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
