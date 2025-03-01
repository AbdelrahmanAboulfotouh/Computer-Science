#include <bits/stdc++.h>
using namespace std;

class Stack{
private:
    struct Node{
        int data{ };
        Node* next;
        Node(int val):data(val){};
    };
    Node* top{ };
public:
    void push(int value)
    {

            Node* new_item = new Node(value);
            new_item->next = top;
            top = new_item;

    }
    int  pop()
    {
        assert(top);
        Node* cur = top;
        top=top->next;
        int val = cur->data;
        delete cur ;
        return val;

    }

void print()
{
        for(auto cur = top ;cur; cur=cur->next)
            cout<<cur->data<<" ";
        cout << endl;
}
int peek()
{
    assert(top);
    return top->data;
}
};
int main()
{

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.print();
    cout<<s.peek();
    return 0;
}