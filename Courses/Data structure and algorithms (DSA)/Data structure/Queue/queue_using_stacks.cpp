#include "stack.h"
class Queue{
    Stack s1;
    Stack s2;
    int added_elements{ };
    int size{ };
    void insert_back(int value)
    {
        while (!s1.isempty())
        {
            s2.push(s1.pop());
        }
        s1.push(value);
        ++added_elements;
        while (!s2.isempty())
        {
            s1.push(s2.pop());
        }


    }

public:
    Queue(int size) : size(size),s1(size),s2(size){};

    void enqueu(int value)
    {
        insert_back(value);
    }
    int dequeue()
    {
        return s1.pop();
    }
    bool is_empty()
    {
        return s1.isempty();
    }


};
int main ()
{
    Queue q(6);
    for(int i{1};i<=3;++i)
    {
        q.enqueu(i);
    }
    cout<<q.dequeue();
    for(int i{4};i<=5;++i)
    {
        q.enqueu(i);
    }
    while (!q.is_empty())
    {
        cout<<q.dequeue()<<endl;
    }
    return 0;
}