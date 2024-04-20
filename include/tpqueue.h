// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

struct SYM {
    char ch;
    int prior;
};

template<typename T, int size>
class TPQueue {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;
    std::size_t count;

public:
    TPQueue() : head(nullptr), count(0) {}

    ~TPQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& elem) {
        Node* newNode = new Node{elem, nullptr};

        if (!head || head->data.prior < elem.prior) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data.prior >= elem.prior) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        ++count;
    }

    T pop() {
        if (!head) {
            throw std::out_of_range("Queue is empty");
        }

        Node* temp = head;
        T data = temp->data;
        head = head->next;
        delete temp;
        --count;
        return data;
    }
};

#endif  // INCLUDE_TPQUEUE_H_
