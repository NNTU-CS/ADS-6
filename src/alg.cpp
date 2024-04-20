#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
  private:
    int front, rear; // измененные имена переменных
    int counter;
    T *data;

  public:
    TPQueue() : front(0), rear(0), counter(0), data(new T[size]) {}
    void push(const T &item) {
      if (counter >= size)
        throw std::string("Full");
      counter++;
      int t1 = rear, h1 = front;
      while (h1 < rear) {
        if (data[h1].prior < item.prior) {
          t1 = h1;
          break;
        }
        h1++;
      }
      for (int i = rear; i > t1; i--)
        data[i % size] = data[(i - 1) % size];
      data[t1 % size] = item;
      rear++;
    }
T pop() {
  if (counter == 0) {
    throw std::string("Empty");
  } else {
    counter--;
    return data[(front++) % size];
  }
}
};

struct SYM {
char ch;
int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
