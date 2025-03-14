#include <bits/stdc++.h>
using namespace std;
class Deque{
private:
    int* array{ };
    int front{ };
    int rear{ };
    int added_elements{ };
    int size{ };
public:
    Deque(int size) : size(size)
    {
        array = new int[size];
    };
    //abstract circular array movement
    int next(int pos)
    {

        return (pos+1)%size;
    }
    int back(int pos)
    {
        return (--pos < 0)? size-1 : pos ;
    }
    bool isEmpty()
    {
        return added_elements == 0;
    }
    bool isFull()
    {
        return added_elements == size;
    }
    void add_back(int value)
    {
        assert(!isFull());
        array[rear] = value;
        rear = next(rear);
        ++added_elements;
    }
    int  pop_front()
    {
        assert(!isEmpty());
        int value = array[front];
        front = next(front);
        --added_elements;
        return value;
    }
    void add_front(int value)
    {
        assert(!isFull());
        front = back(front);
        array[front] = value;
        ++added_elements;
    }
    int pop_back()
    {
        assert(!isEmpty());
        rear = back(rear);
        int value = array[rear];
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
cout<<endl;

    }


};
int main()
{
    Deque dq(6);

    dq.add_front(3);
    dq.add_front(2);
    dq.add_back(4);
    dq.add_front(1);

    dq.display();
    cout << dq.pop_back() << endl;
    dq.display();
    cout << dq.pop_front() << endl;
    dq.display();
    cout << dq.pop_back() << endl;
    cout << dq.pop_front() << endl;
    dq.add_back(7);
    dq.display();
    return 0;
}