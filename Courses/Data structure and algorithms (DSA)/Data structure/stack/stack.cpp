
#include <bits/stdc++.h>
using namespace std;
class Stack{
private:
    int size{ };
    int top {-1};
    int* array{ };


public:
    Stack(int size):size(size)
    {
        array = new int[size];
    };
    bool  isfull()
    {
        return top == size-1;
    }
    bool isempty()
    {
        return top == -1;
    }
    void print()
    {
        assert(!isempty());

        for(int i = top ; i>=0 ; --i)
        {
            cout<<array[i]<<" ";
            cout<<endl;
        }
    }
    void push(int value)
    {
        assert(!isfull());
        array[++top] = value;

    }
    int  pop()
    {
        assert(!isempty());
        return array[top--];
    }
    int peek()
    {
        assert(!isempty());
        return array[top];
    }


};
int main()
{
    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    cout<<s.peek();
    return 0;
}
