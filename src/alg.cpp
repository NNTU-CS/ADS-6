// Copyright 2021 NNTU-CS

#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
using namespace std;

struct SYM {
    char ch;
    int prior;
};

template<typename T, int size>
class TPQueue {
private:
    T * arr;
    int head;
    int count = 0;
public:
    TPQueue() {
        arr = new T[size + 1];
        head = -1;
    }
    void push(T value) {
        if (head == -1) {
            arr[++head] = value;
        }
        else if (head == 0) {
            if (arr[head].prior < value.prior) {
                arr[++head] = value;
            }
            else {
                arr[++head] = value;
                swap(arr[0], arr[head]);
            }
        }
        else {
            count += 1;
            arr[++head] = value;
            for (int i = 0; i < count + 1; ++i) {
                for (int j = 0; j < count + 1; ++j) {
                    if (arr[j].prior > arr[j + 1].prior) {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }
    }
    bool empty() {
        return head == -1;
    }
    T top() {
        return arr[head];
    }
    T pop() {
        count -= 1;
        return arr[head--];
    }
    ~TPQueue() {
        delete[] arr;
    }
};

ostream& operator<<(ostream& os, const SYM& point) {
    os << point.ch << " " << point.prior << endl;
    return os;
}
