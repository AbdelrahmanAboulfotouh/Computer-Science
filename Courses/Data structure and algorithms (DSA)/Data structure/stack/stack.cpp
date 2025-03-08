
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


    void insert_at_bottom(int x)
    {
//base-case
        if(isempty())
        {
            push(x);
        }
        else
        {
            int cur = pop();
             insert_at_bottom(x);
            push(cur);
        }
    }
    void reverse()
    {


        if(isempty())
            return;

            int cur_top = pop();
               reverse();
            insert_at_bottom(cur_top);





    }
};
int main()
{
    Stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    //s.print();
    s.insert_at_bottom(25);
    s.print();
   s.reverse();
    s.print();
    return 0;
}
