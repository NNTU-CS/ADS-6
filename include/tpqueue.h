#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>
#include <cstddef>

template<typename T, int size>
class TPQueue {
 private:
    T* buffer;
    std::size_t capacity;
    std::size_t count;

 public:
    TPQueue() : buffer(new T[size]), capacity(size), count(0) {}

    ~TPQueue() {
        delete[] buffer;
    }

    void push(const T& item) {
        if (count == capacity) {
            throw std::out_of_range("Queue is full");
        }

        std::size_t index = count;
        while (index > 0 && buffer[index - 1].priority >= item.priority) {
            buffer[index] = buffer[index - 1];
            --index;
        }
        buffer[index] = item;
        ++count;
    }

    T pop() {
        if (count == 0) {
            throw std::out_of_range("Queue is empty");
        }

        T tmp = buffer[count - 1];
        --count;
        return tmp;
    }
};

struct Item {
  char symbol;
  int priority;
};

#endif  // INCLUDE_TPQUEUE_H_
