// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T, int size>
class TPQueue {
 private:
  T arr[size] = {};
  int start_index = 0;
  int end_index = 0;
  int fullness = 0;

  int norm(int i) { return (i + size) % size; }

  void empty_place(int in_index) {
    for (int i = 0; i < (end_index - in_index + size) % size; ++i) {
      arr[norm(end_index - i)] = arr[norm(end_index - i - 1)];
    }
  }

 public:
  void push(T new_elem) {
    if (fullness == size) {
      return;
    }
    int in_index = end_index;
    while (true) {
      if ((in_index == start_index) ||
          ((arr[in_index - 1].prior >= new_elem.prior) &&
           (arr[in_index - 1].prior != 0))) {
        break;
      }
      in_index = norm(in_index - 1);
    }
    empty_place(in_index);
    fullness += 1;
    end_index = norm(end_index + 1);
    arr[in_index] = new_elem;
  }

  T pop() {
    T res = arr[start_index];
    start_index = norm(start_index + 1);
    fullness -= 1;

    return res;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
