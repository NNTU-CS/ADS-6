// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
private:
    T data[Size];
    int begin, end, count;

 public:
    TPQueue() : begin(0), end(0), count(0) {}

    void push(const T &item) {
        if (count >= Size) {
            throw std::string("Full");
        }
        int i = end - 1;
        while (i >= begin && item.prior > data[i % Size].prior) {
            data[(i + 1) % Size] = data[i % Size];
            i--;
        }
        data[(i + 1) % Size] = item;
        end = (end + 1) % Size;
        count++;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
