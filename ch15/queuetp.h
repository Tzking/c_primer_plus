//
// Created by Tarryzking on 2023/5/28.
//

#ifndef DEMO_QUEUETP_H
#define DEMO_QUEUETP_H

template<class Item>
class Queue {
private:
    enum {
        Q_SIZE = 10
    };

    class Node {
    public:
        Item item;
        Node *next;

        Node(const Item &i) : item(i), next(0) {}
    };

    Node *front;
    Node *rear;
    int items;
    const int q_size;

    Queue(const Queue &q) : q_size(0) {}

    Queue &operator=(const Queue &q) { return *this; }

public:
    Queue(int s = Q_SIZE);

    ~Queue();

    bool isempty() const {
        return items == 0;
    }

    bool isfull() const {
        return items == q_size;
    }

    int queue_count() const {
        return items;
    }

    bool enqueue(const Item &i);

    bool dequeue(Item &i);
};

template<class Item>
bool Queue<Item>::dequeue(Item &i) {
    if (front == 0)
        return false;
    i = front->item;
    items--;
    Node *temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = 0;
    return true;
}

template<class Item>
bool Queue<Item>::enqueue(const Item &i) {
    if (isfull())
        return false;
    Node *add = new Node(i);
    items++;
    if (front == 0)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

template<class Item>
Queue<Item>::~Queue() {
    Node *temp;
    while (front != 0) {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template<class Item>
Queue<Item>::Queue(int s) : q_size(s) {
    front = rear = 0;
    items = 0;
}

#endif //DEMO_QUEUETP_H
