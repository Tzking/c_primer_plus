#include "queue.hpp"
#include <cstdlib>

Queue::Queue(int qs) : q_size(qs)
{
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue()
{
    Node * temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == q_size;
}

int Queue::queue_conut() const
{
    return items;
}

// 入列
bool Queue::enqueue(const Item & item)
{
    if (isfull())
        return false;
    Node * add = new Node;

    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

// 出列
bool Queue::dequeue(Item & item)
{
    if (front == nullptr)
        return false;
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = nullptr;
    return true;    
}

void Customer::set(long when)
{
    process_time = std::rand() % 3 + 1;
    arrive = when;
}
