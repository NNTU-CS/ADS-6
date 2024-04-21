// Copyright 2022 NNTU-CS
#include <string>

#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<class T, int size>
class TPQueue {
 private:
    T* Qdata;
    int taked;

 public:
    TPQueue() :taked(0) {
        Qdata = new T[size];
        for (int i = 0; i < size; i++) {
            Qdata[i].ch = '-';
            Qdata[i].prior = 0;
        }
    }

    void push(T str_sym) {
        if (taked >= size) {
            throw std::string("Queue is Full");
        } else {
            if (taked == 0) {
                Qdata[taked++] = str_sym;
            } else {
                for (int i = taked - 1; i >= -1; i--) {
                    if (str_sym.prior <= Qdata[i].prior) {
                        Qdata[i + 1] = Qdata[i];
                        if (i == -1) {
                            Qdata[0] = str_sym;
                            taked++;
                            break;
                        }
                    } else {
                        Qdata[i + 1] = str_sym;
                        taked++;
                        break;
                    }
                }
            }
        }
    }

    T pop() {
        return Qdata[--taked];
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
