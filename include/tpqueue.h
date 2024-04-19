// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
   private:
    T *arr;
    int size;
    int begin, end;
    int count;

   public:
    TPQueue(int s = 100) : size(s), begin(0), end(0), count(0) {
        arr = new T[size + 1];
    }
    ~TPQueue() { delete[] arr; }

    csharp Copy code void push(const T &item) {
        if (count < size) {
            if (end == 0) {
                arr[end++] = item;
                count++;
            } else {
                int index = end - 1;
                while (index >= begin && item.prior > arr[index].prior) {
                    arr[index + 1] = arr[index];
                    index--;
                }
                arr[index + 1] = item;
                end++;
                count++;
            }
            if (end > size) end -= size + 1;
        }
    }

    T pop() {
        if (count > 0) {
            count--;
            if (begin < size)
                begin++;
            else
                begin = 0;
            return arr[begin - 1];
        }
    }
    T get() const { return arr[begin]; }
    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == size; }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
