// Copyright 2022 NNTU-CS
#ifndef INCLUDETPQUEUE_H
#define INCLUDETPQUEUE_H

template<typename T, int size>
class TPQueue {
 private:
    T* buffer;
    std::size_t maxCapacity;
    std::size_t itemCount;

 public:
    TPQueue() : buffer(new T[size]), maxCapacity(size), itemCount(0) {}

    ~TPQueue() {
        delete[] buffer;
    }

    void enqueue(const T& element) {
        if (itemCount == maxCapacity) {
            throw std::out_of_range("Queue is full");
        }

        std::size_t index = itemCount;
        while (index > 0 && buffer[index - 1].priority >= element.priority) {
            buffer[index] = buffer[index - 1];
            --index;
        }
        buffer[index] = element;
        ++itemCount;
    }

    T dequeue() {
        if (itemCount == 0) {
            throw std::out_of_range("Queue is empty");
        }

        T temp = buffer[itemCount - 1];
        --itemCount;
        return temp;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDETPQUEUE_H
