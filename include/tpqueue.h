// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
private:
	T* mas;
	int beg, end, k; //begin, end, count;
public:
	TPQueue():beg(0),end(0),k(0),mas(new T[size]) {}
	bool empty() const {
		return k == 0;
	}
	void push(const T& f) {
		int i;
		if (k >= size)
			throw std::string("Full!");
			else if (k == 0) {
				k++;
				mas[0] = f;
			} else {
			k++;
			for (i = end; i >= beg; i--) {
				if (f.prior > mas[i].prior)
					mas[i + 1] = mas[i];
				else break;
			}
			mas[i + 1] = f;
			end++;
		}
	}
		T pop() {
			if (k != 0)
				k--;
			return mas[beg++ % size];
	}
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
