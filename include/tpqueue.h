// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
  T* data;
  int begin, end, count;

 public:
  TPQueue(): begin(0), end(0), count(0) { data = new T[size]; }

  void push(const T& sym) {
    if (count >= size) {
      throw std::string("Full");
    }
    count++;
    int pos = end;

    for (int i = begin; i < end; i++) {
      if (data[i].prior < sym.prior) {
        pos = i;
        break;
      }
    }

    for (int i = end - 1; i >= pos; i--) {
      data[(i + 1) % size] = data[i % size];
    }
    
    data[pos % size] = sym;
    end++;
  }

  T pop() {
    if (count == 0) {
      throw std::string("Empty");
    } else {
      count--;
      return data[begin++ % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
