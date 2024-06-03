// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  private:
    T* arr;
    int size;
    int count;

public:
    TPQueue(int s = 100) : size(s), count(0) {
        arr = new T[size];
    }

    ~TPQueue() {
        delete[] arr;
    }

    void push(const T& item) {
        if (count < size) {
            if (count == 0) {
                arr[count++] = item;
            } else {
                int i = count - 1;
                while (i >= 0 && item.prior > arr[i].prior) {
                    arr[i + 1] = arr[i];
                    i--;
                }
                arr[i + 1] = item;
                count++;
            }
        } else {
            std::cerr << "Queue is full" << std::endl;
        }
    }

    T pop() {
        if (count > 0) {
            return arr[--count];
        } else {
            std::cerr << "Queue is empty" << std::endl;
            return T();
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
