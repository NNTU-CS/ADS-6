// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
  char ch;
  int prior;
};

template<typename T>
class TPQueue {
private:
  struct Node {
    T data;
    Node* next;
  };
  Node* first;
  Node* last;
public:
  TPQueue() : first(nullptr), last(nullptr) {}
  ~TPQueue() {
    while (first) {
      Node* tmp = first->next;
      delete first;
      first = tmp;
    }
  }
  void push(const T& elem) {
    Node* temp = new Node{elem, nullptr};
    if (!first) {
      first = temp;
      last = temp;
    } else {
      Node* curr = first;
      Node* prev = nullptr;
      while (curr && elem.prior <= curr->data.prior) {
        prev = curr;
        curr = curr->next;
      }
      if (!prev) {
        temp->next = first;
        first = temp;
      } else {
        prev->next = temp;
        temp->next = curr;
        if (!curr) last = temp;
      }
    }
  }
  T pop() {
    if (empty())
      throw “Queue is empty”;
    T result = first->data;
    Node* temp = first;
    first = first->next;
    delete temp;
    return result;
  }
  bool empty() const {
    return first == nullptr;
  }
};
#endif  // INCLUDE_TPQUEUE_H_
