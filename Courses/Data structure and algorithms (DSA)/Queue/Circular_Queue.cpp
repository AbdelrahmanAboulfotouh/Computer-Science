#include <bits/stdc++.h>
using namespace std;
class Queue{
private:
    int* array{ };
    int front{ };
    int rear{ };
    int added_elements{ };
    int size{ };
public:
    Queue(int size) : size(size)
    {
        array = new int[size];
    };
    //abstract circular array movement
    int next(int pos)
    {

        return (pos+1)%size;
    }
    bool isEmpty()
    {
        return added_elements == 0;
    }
    bool isFull()
    {
        return added_elements == size;
    }
    void Enqueue(int value)
    {
        assert(!isFull());
        array[rear] = value;
        rear = next(rear);
        ++added_elements;
    }
    int  dequeue()
    {
        assert(!isEmpty());
        int value = array[front];
        front = next(front);
        --added_elements;
        return value;
    }
    void display()
    {
        if(isEmpty()) {
            cout << "Nothing to display";
            return;
        }
        for(int i{0}, cur =front;i<added_elements;++i)
        {
            cout<<array[cur]<<" ";
            cur = next(cur);
        }


    }



};