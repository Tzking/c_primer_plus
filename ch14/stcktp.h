//
// Created by Tarryzking on 2023/5/22.
//

#ifndef DEMO_STCKTP_H
#define DEMO_STCKTP_H

template<class Type>
class Stack {
private:
    enum {
        Size = 10
    };
    int stack_size;
    Type *items;
    int top;
public:
    explicit Stack(int s = Size);

    Stack(const Stack &s);

    ~Stack() { delete[] items; }

    bool isempty() { return top == 0; }

    bool isfull() { return top == stack_size; }

    bool push(const Type &item);

    bool pop(Type &item);

    Stack &operator=(const Stack &s);
};

template<class Type>
Stack<Type> &Stack<Type>::operator=(const Stack &s) {
    if (this == &s) {
        return *this;
    }
    delete[] items;
    stack_size = s.stack_size;
    top = s.top;
    items = new Type[stack_size];
    for (int i = 0; i < top; ++i) {
        items[i] = s.items[i];
    }
    return *this;
}

template<class Type>
Stack<Type>::Stack(const Stack &s) {
    stack_size = s.stack_size;
    top = s.top;
    items = new Type[stack_size];
    for (int i = 0; i < top; ++i) {
        items[i] = s.items[i];
    }
}

template<class Type>
Stack<Type>::Stack(int s) : stack_size(s), top(0) {
    items = new Type[stack_size];

}

template<class Type>
bool Stack<Type>::push(const Type &item) {
    if (top < stack_size) {
        items[top++] = item;
        return true;
    } else
        return false;
}

template<class Type>
bool Stack<Type>::pop(Type &item) {
    if (top > 0) {
        item = items[--top];
        return true;
    } else
        return false;
}


#endif //DEMO_STCKTP_H
