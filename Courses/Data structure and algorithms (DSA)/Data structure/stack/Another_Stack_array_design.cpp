/*

#1: Another Stack array design
●
 implement this Stack with the following design choices

Discuss the time complexity of the methods

Instead of top, used int added_elements to represent number of added elements so far
Instead of assert, push, pop, peek ⇒ returns bool to indicate success / failure
If we push 10, 20, 30 in Stack, the array content is: {30, 20, 10}
■ That is, array[0] represents the top
Discuss how even minor design choices affect our data structure!
Change the main() function to reuse the new interface of the code


  */

#include <bits/stdc++.h>
using namespace std;
class Stack{
private:
    int size{ };
    int added_elements {-1};
    int* array{ };

public:
    Stack(int size): size(size)
    {
        array = new int[size];
    };
    bool  isfull()
    {
        return added_elements == size - 1;
    }
    bool isempty()
    {
        return added_elements == -1;
    }
    bool print()
    {
        if(isempty())
            return false;

        for(int i {0} ; i <= added_elements ; ++i)
        {
            cout << array[i] << " ";
            cout<<endl;
        }
        return true;
    }
    // Time : O(N) ,  space o(1)
    bool  push(int value)
    {
        if(isfull())
            return false ;
        for (int i = added_elements; i >= 0 ; i--)
            array[i+1] = array[i] ;
        array[0] = value;
        ++added_elements;
        return true;
    }
    // Time : O(N) ,  space o(1)
    int  pop()
    {
        if(isempty())
            return false;
        int top = array[0];
        for (int i {0}; i <= added_elements ; i++)
            array[i] = array[i+1];
        --added_elements;
        return top;
    }
    int peek()
    {
        if(isempty())
            return false;
        return array[0];
    }
    int Added_elements()
    {
        return added_elements + 1 ;
    }


};
int main()
{
    Stack stack1(5);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.pop();
    stack1.print();
    return 0;
}
