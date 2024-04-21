// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    std::list<T> Query;
 public:
    void push(T a) {
        if (!Query.empty()) {
            for (auto i = Query.cbegin(); i != Query.cend(); ++i) {
                if (a.prior <= (*i).prior) {
                    Query.insert(i, a);
                    return;
                }
            }
        }
        Query.push_back(a);
    }
    const T pop() {
        T res = Query.back();
        Query.pop_back();
        return res;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
