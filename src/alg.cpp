// Copyright 2021 NNTU-CS
#include <iostream>

struct SYM {
    char ch;
    int prior;
};

template<typename T>
class TPQueue {
private:
    T *arr;         
    int size;      
    int begin,      
        end;        

    int count;       
public:
    TPQueue(int =100);          
    ~TPQueue();                 
    void push(const T &); 
    T pop();             
    T get() const;       
    bool isEmpty() const;  
    bool isFull() const;  
};

template<typename T>
TPQueue<T>::TPQueue(int sizeQueue) :
    size(sizeQueue),
    begin(0), end(0), count(0) {
    arr = new T[size + 1];
}

template<typename T>
TPQueue<T>::~TPQueue() {
    delete[] arr;
}

template<typename T>
void TPQueue<T>::push(const T & item) {
    if (count < size) {
        int i = end - 1; 
        while (i >= begin && item.prior > arr[i].prior) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = item;
        end++;
        count++;
        if (end > size)
            end -= size + 1; 
    }
    else
        std::cerr << "Queue is full!" << std::endl;
}

template<typename T>
T TPQueue<T>::pop() {
    if (count > 0) {
        T item = arr[begin++];
        count--;
        if (begin > size)
            begin -= size + 1; 
        return item;
    }
    else {
        std::cerr << "Queue is empty!" << std::endl;
        return T();
    }
}

template<typename T>
T TPQueue<T>::get() const {
    return arr[begin];
}

template<typename T>
bool TPQueue<T>::isEmpty() const {
    return count == 0;
}

template<typename T>
bool TPQueue<T>::isFull() const {
    return count == size;
}
