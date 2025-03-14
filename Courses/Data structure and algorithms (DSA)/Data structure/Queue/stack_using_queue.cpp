#include "Queue.h"
class Stack{
    Queue q;
    int added_elements{ };
    int size{};
public:
    Stack(int size): size(size),q(size){};
    void queue_front_push(int value)
    {
        q.Enqueue(value);
        ++added_elements;

        int items = added_elements;
        while (items--)
        {
            q.Enqueue(q.dequeue());
        }
    }
public:
    void push(int value)
    {
        queue_front_push(value);
    }
    int pop()
    {
        return q.dequeue();
    }
    int peek()
    {
        return q.Front();
    }
    bool isEmpty()
    {
        return q.isEmpty();
    }
};
int main()
{
    Stack St( 3);
    St.push(10);
    St.push(20);
    St.push(30);
    while (!St.isEmpty())
    {
        cout<<St.peek()<<" ";
        St.pop();
    }

    return 0;
}