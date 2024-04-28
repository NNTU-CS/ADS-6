// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
private:
  int start, end, cnt;
  T *data;
public:
  TPQueue() : cnt(0), end(0), data(new T[size]) {}
  T pop() {
    if (cnt == 0) throw std::string("Queue is empty");
    cnt--;
    return data[start++ % size];
  }
  void push(const T &item) {
    if (cnt >= size) throw std::string("Queue is full");
    cnt++;
    int index = end;
    for (int i = start; i < end; i++) {
      if (data[i].prior < item.prior) {
        index = i;
        break;
      }
    }
    for (int i = end; i > index; i--)
      data[i % size] = data[(i - 1) % size];
    data[index % size] = item;
    end++;
  }
};

struct SYM {
  char ch;
  int prior;
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
