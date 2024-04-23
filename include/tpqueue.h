// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int Size>
class TPQueue {
private:
    T items[Size];
    int front_index, rear_index, num_items;

public:
    TPQueue() : front_index(0), rear_index(0), num_items(0) {}

    void add(const T &item) {
        int position;
        if (num_items >= Size) {
            throw std::string("Full");
        } else {
            if (num_items == 0) {
                items[front_index] = item;
                num_items++;
            } else {
                for (position = rear_index; position >= front_index; position--) {
                    if (item.prior > items[position % Size].prior) {
                        items[(position + 1) % Size] = items[position % Size];
                    } else {
                        break;
                    }
                }
                rear_index++;
                items[(position + 1) % Size] = item;
                num_items++;
            }
        }
    }

    T remove() {
        if (num_items == 0) {
            throw std::string("Queue is empty");
        } else {
            num_items--;
            T removed_item = items[front_index++ % Size];
            return removed_item;
        }
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_