// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
   T* arr;
   int Size;
   int count, head, tail;
 public:
   TPQueue() {
       count = 0, head = 0, tail = 0;
       arr = new T[Size];
       arr = new T[size];
   }
    ~TPQueue() {
        delete[] arr;
    }
    void push(const T& item) {
        if (count < size)
            count++;
            int N = tail;
        for (int i = head; i < tail; i++) {
            if (arr[i].prior < item.prior) {
                N = i;
                break;
            }
        }
        for (int i = (tail - 1); i >= N; i--) {
            arr[(i + 1) % size] = arr[i % size];
        }
        arr[N % size] = item;
        tail++;
    }
    T pop() {;
        if (count == 0)
            throw 0;
        count--;
        return arr[(head += 1) % size];
    }
};

struct SYM {
	char ch;
	int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
