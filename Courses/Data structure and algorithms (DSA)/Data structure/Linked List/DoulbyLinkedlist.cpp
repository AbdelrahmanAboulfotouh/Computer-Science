
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data { };
    Node* next { };
    Node* pre { };
    Node (int data) : data(data) {};
     void  set (Node* pre, Node* next)
     {
         this->pre = pre;
         this->next = next;
     }

};

class  DoulbyLinkedlist
{
private:
    Node* Head {};
    Node* Tail {};
    int Length { };
public:
    void print_Reversed()
    {
        for(Node* cur =Tail ; cur ; cur = cur->next)
        {
            cout<<cur->data;
        }
    }
    void  link (Node* first, Node* second)
    {
        if(first)
            first->next = second;
        if(second)
            second->pre = first;
    }

    void insert_back(int value)
    {
        Node* temp = new Node(value);
        if(!Head)
        {
            Head = Tail = temp;
        }
        else
        {
            link(Tail,temp);
            Tail = temp;
        }
    }
    void insert_front(int value)
    {
        Node* temp = new Node(value);
        if(!Head)
        {
            Head = Tail = temp;
        }
        else
        {
            link(temp, Head);
            Head = temp;
        }
    }
    void embed_after(Node* node_before, int value)
    {
        Node* middle = new Node(value);
        Node* node_after = node_before->next;
        link(node_before,middle);
        link(middle,node_after);
    }
    void insert_sorted (int value)
    {
        if(!Head)
        {
            Head->data =  value;
            Tail =Head;
        }
        else
        {
            if(Tail->data > value)
            {
                for(Node* cur = Head ; cur ; cur = cur->next)
                {
                    if(cur->data >= value)
                    {
                        embed_after(cur->pre,value);
                        break;
                    }
                }
            }
            else
            {
                insert_back(value);
            }
        }
    }
    void delete_front()
    {
        if(!Head)
            return;
        Node* tmp = Head;
        Head= Head->next;
        Head->pre = nullptr;
        delete tmp;
        if(!Head)
            Tail = nullptr;
    }
Node* delete_and_link (Node* cur)
{
        Node* ret = cur->pre;
    link(cur->pre, cur->next);
    delete cur ;
    return ret;
}
void  delete_node_with_key(int key)
{
        if(!Length)
            return;
        if(Head->data == key)
            delete_front();
        else
        {
            for(Node* cur = Head ; cur ; cur = cur->next)
            {
                if(cur->data == key)
                {
                    cur = delete_and_link(cur);
                    if(!cur->next)
                        Tail = cur;
                    break;
                }
            }
        }
}
};
