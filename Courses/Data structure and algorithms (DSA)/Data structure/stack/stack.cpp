
#include <bits/stdc++.h>
using namespace std;
class stack{
private:
    int size{ };
    int top {-1};
    int* array{ };
    stack(int size):size(size)
    {
        array = new int[size];
    };
public:
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
            cout<<array[top--]<<" ";
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
