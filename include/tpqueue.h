// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  private :
      int front, rear, itemCount;
  T *storage;

  public :
      TPQueue() : front(0), rear(0), itemCount(0), storage(new T[size]) {
  }

  void push(const T &item) {
    int currentNum;
    if (itemCount >= size) {
      throw std::string("Queue is full");
    } else {
      if (itemCount == 0) {
        storage[front] = item;
        itemCount++;
      } else {
        for (currentNum = rear; currentNum >= front; currentNum--) {
          if (item.prior > storage[currentNum % size].prior) {
            storage[(currentNum + 1) % size] = storage[currentNum % size];
          } else {
            break;
          }
        }
        rear++;
        storage[(currentNum + 1) % size] = item;
        itemCount++;
      }
    }
  }

  T pop() {
    if (itemCount == 0) {
      throw std::string("Queue is empty");
    } else {
      itemCount--;
      return storage[(front + 1) % size];
      return storage[(front++) % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
