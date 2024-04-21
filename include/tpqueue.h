// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>

struct SYM {
    char ch;
    int prior;
};

template<typename T>
class TPQueue {
 private:
    struct ITEM {
        T data;
        ITEM* next;
    };
    ITEM* head;
    ITEM* tail;

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}

    ~TPQueue() {
        while (head) {
            ITEM* temp = head->next;
            delete head;
            head = temp;
        }
    }

    void push(const T& data) {
        ITEM* temp = new ITEM;
        temp->data = data;
        temp->next = nullptr;

        if (!head) {
            head = temp;
            tail = temp;
        } else {
            if (temp->data.prior > head->data.prior) {
                temp->next = head;
                head = temp;
            } else {
                ITEM* current = head;
                while (current->next) {
                    if (temp->data.prior > current->next->data.prior)
                        break;
                    current = current->next;
                }
                temp->next = current->next;
                current->next = temp;
                if (!temp->next)
                    tail = temp;
            }
        }
    }

    T pop() {
        if (!head)
            throw std::out_of_range("Queue is empty");

        ITEM* temp = head;
        T data = head->data;
        head = head->next;
        delete temp;
        return data;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
