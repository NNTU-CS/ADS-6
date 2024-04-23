// Copyright 2022 NNTU-CS
#include "tpqueue.h"

int main() {
    TPQueue<SYM, 5> pqueue;
    pqueue.push(SYM{'a', 4});
    pqueue.push(SYM{'b', 4});
    pqueue.push(SYM{'c', 9});
    SYM c1 = pqueue.pop();
    SYM c2 = pqueue.pop();
    SYM c3 = pqueue.pop();
}
