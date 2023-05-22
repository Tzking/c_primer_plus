//
// Created by 21997 on 2023/5/22.
//

#ifndef DEMO_STACKTP_H
#define DEMO_STACKTP_H

template<class Type>
class Stack {
private:
    enum {
        max = 10
    };
    Type items[max];
    int top;
public:
    Stack();

    bool isempty();

    bool isfull();

    bool push(const Type &item);

    bool pop(Type &item);
};

template<class Type>
bool Stack<Type>::pop(Type &item) {
    if (top > 0) {
        item = items[--top];
        return true;
    } else
        return false;
}

template<class Type>
bool Stack<Type>::push(const Type &item) {
    if (top < max) {
        items[top++] = item;
        return true;
    } else
        return false;
}

template<class Type>
bool Stack<Type>::isfull() {
    return top == max;
}

template<class Type>
bool Stack<Type>::isempty() {
    return top == 0;
}

template<class Type>
Stack<Type>::Stack() {
    top = 0;
}


#endif //DEMO_STACKTP_H
