// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
   private:
      T arr[Size];
      int begin, end, count;

    public:
      TPQueue() : begin(0), end(0), count(0) {}  
      ~TPQueue() {}
      void push(const T& item) {
         assert(count < Size);
         count++;
         int i = end;
         while (i != begin && item.prior > arr[(i - 1 + Size) % Size].prior) {
            arr[i % Size] = arr[(i - 1 + Size) % Size];
            i = (i - 1 + Size) % Size;
         }
         arr[i % Size] = item;
         end = (end + 1) % Size;
      }
T pop() {
   assert(count > 0);
   T item = arr[begin++ % Size];
   count--;
   return item;
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
