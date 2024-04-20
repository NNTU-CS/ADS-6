#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
 private:
    int begin, end, count;
    T *data;

 public:
    TPQueue() : begin(0), end(0), count(0), data(new T[size]) {}

    T pop() {
        if (count == 0) {
            throw std::string("Empty!!!");
        } else {
            count--;
            return data[begin++ % size];
        }
    }

    void push(const T &item) {
        if (count >= size)
            throw std::string("Full!!!");
        count++;
        int Index = end;
        for (int i = begin; i < end; i++) {
            if (data[i].prior < item.prior) {
                Index = i;
                break;
            }
        }
        for (int i = end; i > Index; i--)
            data[i % size] = data[(i - 1) % size];
        data[Index % size] = item;
        end++;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
