// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T>
class TPQueue {
private:
    std::vector<T> array;

public:
    void push(const T& elem) {
        if (array.empty()) {
            array.push_back(elem);
        } else {
            int i = 0;
            for (i = 0; i < array.size(); ++i) {
                if (elem.prior > array[i].prior) {
                    break;
                }
            }
            array.insert(array.begin() + i, elem);
        }
    }

    void pop() {
        if (!array.empty()) {
            array.erase(array.begin());
        } else {
            std::cout << "Queue is empty." << std::endl;
        }
    }

    T front() const {
        if (!array.empty()) {
            return array.front();
        } else {
            std::cout << "Queue is empty." << std::endl;
            return T();
        }
    }

    bool isEmpty() const {
        return array.empty();
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
