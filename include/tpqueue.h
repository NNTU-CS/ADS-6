// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
struct ITEM {
    T data;
    int prior;
    ITEM<T>* next;
};

template<typename T, int size>
class TPQueue {
 private:
    ITEM<T>* head;
    ITEM<T>* tail;

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    ~TPQueue() {
        while (head) {
            ITEM<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push(const T& data) {
        int prior = data.prior;
        ITEM<T>* temp = new ITEM<T>;
        temp->data = data;
        temp->prior = prior;
        temp->next = nullptr;
        if (!head || prior > head->prior) {
            temp->next = head;
            head = temp;
            if (!tail) {
                tail = temp;
            }
        } else {
            ITEM<T>* current = head;
            while (current->next && current->next->prior >= prior) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
            if (!current->next) {
                tail = temp;
            }
        }
    }
    T pop() {
        if (!head) {
            return T();
        }
        ITEM<T>* temp = head;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        T data = temp->data;
        delete temp;
        return data;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
