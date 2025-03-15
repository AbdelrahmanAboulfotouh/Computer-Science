#include "stack.h"
class Queue{
    Stack s1;
    Stack s2;
    int added_elements{ };
    int size{ };
    int pop_back()
    {

        while (!s1.isempty())
        {
            s2.push(s1.pop());
        }
        int top = s2.pop();
        while (!s2.isempty())
        {
            s1.push(s2.pop());
        }
        return top;

    }

public:
    Queue(int size) : size(size),s1(size),s2(size){};

    void enqueu(int value)
    {
        s1.push(value);
        ++added_elements;
    }
    int dequeue()
    {
        --added_elements;
        return pop_back();
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
    cout<<q.dequeue()<<endl;
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