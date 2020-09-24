//
// Created by 11135 on 2020/8/7.
//

#ifndef C_PRIMER_STACK_H
#define C_PRIMER_STACK_H

typedef unsigned long Item;

class Stack {
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
};


#endif //C_PRIMER_STACK_H
