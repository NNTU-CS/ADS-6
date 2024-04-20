// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int begin;
    int end;
    int count;
 public:
    TPQueue() : begin(0), end(0), count(0) {
        arr = new T[size];
    }

    ~TPQueue() {
        delete[] arr;
    }

    void push(const T& item) {
        if (count < size) {
            if (count == 0) {
                arr[end] = item;
            } else {
                int current = end;
                while (arr[current].prior >= item.prior && current != begin) {
                    int prev = (current == 0) ? size - 1 : current - 1;
                    arr[current] = arr[prev];
                    current = prev;
                }
                arr[current] = item;
            }
            end = (end + 1) % size;
            count++;
        }
    }

    T pop() {
        if (count > 0) {
            T item = arr[begin];
            begin = (begin + 1) % size;
            count--;
            return item;
        }
        throw "Queue is empty";
    }
};
struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
