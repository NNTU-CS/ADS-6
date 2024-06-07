// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
public:
    void push(const T& elem) {
        if (this->empty()) {
            TQueue<T>::push(elem);
        } else {
            bool added = false;
            for (int i = 0; i < TQueue<T>::size(); ++i) {
                if (elem.prior > TQueue<T>::operator.prior) {
                    TQueue<T>::push(i, elem);
                    added = true;
                    break;
                }
            }
            if (!added) {
                TQueue<T>::push(elem);
            }
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
