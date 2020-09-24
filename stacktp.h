//
// Created by 11135 on 2020/8/16.
//

#ifndef C_PRIMER_STACKTP_H
#define C_PRIMER_STACKTP_H

template <class Type>
class Stack
{
private:
    enum {MAX = 10};
    Type items[MAX];
    int top;
public:
    Stack();
    bool istempty();
    bool isfull();
    bool push(const Type & item);
    bool pop(Type & item);
};

template <class Type>
Stack<Type>::Stack() {
    top = 0;
}

template <class Type>
bool Stack<Type>::istempty() {
    return top == 0;
}

template <class Type>
bool Stack<Type>::isfull() {
    return top == MAX;
}

template <class Type>
bool Stack<Type>::push(const Type &item) {
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <class Type>
bool Stack<Type>::pop(Type &item) {
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

#endif //C_PRIMER_STACKTP_H
