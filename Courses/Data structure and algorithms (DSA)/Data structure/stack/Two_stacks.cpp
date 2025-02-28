
#include <bits/stdc++.h>
using namespace std;
class Stack{
private:
    int size{ };
    int top_1 { };
    int top_2{ };
    int* array{ };


public:
    Stack(int size):size(size),top_1(-1),top_2(size)
    {
        array = new int[size];

    };

    bool  isfull()
    {
        return abs(top_1 - top_2) == 1;
    }
    bool isempty()
    {
        return (top_1 == -1 and top_2 == size);
    }
    void print()
    {
        assert(!isempty());

            for(int i = top_1 ; i >= 0 ; --i)
            {
                cout << array[i] << " ";
            }
        cout<<endl;
            for(int i = top_2 ; i<size; ++ i)
            {
                cout<<array[i]<<" ";
            }
            cout<<endl;

    }
    void push(int stack_no, int value)
    {
        assert(!isfull());
            if(stack_no == 1)
            array[++top_1] = value;
            else
                array[--top_2] = value;


    }
    int  pop(int stack_no)
    {
        assert(!isempty());
        if(stack_no == 1)
        {
            return array[top_1--];

        }
        else
            return array[top_2++];
    }
    int peek(int stack_no)
    {
        assert(!isempty());
        int idx = stack_no == 1 ? top_1  : (top_2);
        return array[idx];
    }


};
