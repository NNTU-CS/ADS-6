// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
private:
    T* arr; // массив с данными
    int count; // текущее количество элементов
    int rear; // индекс конца очереди
    int front; // индекс начала очереди
public:
    TPQueue() : count(0), rear(0), front(0) {
        arr = new T[size];
    }

    ~TPQueue() {
        delete[] arr;
    }

    void push(const T& item, int prior) {
        if (count < size) {
            if (count == 0) {
                arr[rear] = item;
            }
            else {
                int i = rear - 1;
                while (i >= front && prior > arr[i].prior) {
                    arr[(i + 1 + size) % size] = arr[i];
                    i--;
                }
                arr[(i + 1 + size) % size] = item;
            }
            rear = (rear + 1) % size;
            count++;
        }
    }

    T pop() {
        if (count > 0) {
            T item = arr[front];
            front = (front + 1) % size;
            count--;
            return item;
        }
        else {
            return T();
        }
    }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
