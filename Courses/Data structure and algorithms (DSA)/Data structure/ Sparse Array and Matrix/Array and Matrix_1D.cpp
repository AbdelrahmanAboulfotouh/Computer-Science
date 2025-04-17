#include <iostream>
using namespace std;
struct Node{
    int data{ };
    int idx{ };
    Node* next{ };
    Node* pre{ };
    Node(int data,int idx):data(data),idx(idx){};
};
class ArrayLinkedList{
private:
    Node* Head{ };
    int length{ };
    int acutal_length{ };
    void link(Node* first, Node* last)
    {
        if(first)
            first->next = last;
        if(last)
            last->pre = first;
    }
public:
    Node* get_head(){return  Head;}
    ArrayLinkedList(int length):length(length){};
    void set_value(int value, int index)
    {

        bool Found = false;
        for(auto cur = Head;cur;cur=cur->next) {
            if (cur->idx >= index) {
                cur->data = value;
                Found = true;
                break;
            }
        }
        if(!Found)
        {
            Node* new_item = new Node(value,index);
            if(!Head) {
                Head = new_item;
                ++acutal_length;
                return;
            }
            auto cur =Head;
            while (cur and cur->next and cur->idx < index)
                cur = cur->next;
            if(cur and cur->idx < index) {
                Node *tmp = cur->next;
                link(cur, new_item);
                link(new_item, tmp);
                ++acutal_length;

            }
            else if(cur and cur->idx > index)
            {
                Node *tmp = cur->pre;
                link(new_item, cur);
                link(tmp,new_item);
                ++acutal_length;

            }
       }

    }
    void print_array_nonzero()
    {
        for(auto cur = Head;cur;cur=cur->next)
        {
           std::cout<<cur->data<<" ";
        }
        cout<<endl;
    }
    void print(){
        auto cur = Head ;
        for(int c{0};  c<length ;++c)
        {
            if(cur and cur->idx == c) {
                cout << cur->data << " ";
                cur = cur->next;
            }
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
    int get_value(int index)
    {
        for(auto cur = Head; cur ; cur = cur->next)
        {
            if(cur->idx == index)
                return cur->data;
        }
        return { };
    }
    void add(ArrayLinkedList List2)
    {
        if(length != List2.length)
            throw std::runtime_error("Something went wrong with addition!");

        auto cur1 = Head;
        auto cur2  = List2.Head;
        while (cur1 and cur2)
        {
            if(cur1->idx == cur2->idx)
            {
                cur1->data+=cur2->data;
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            else if(cur1->idx < cur2->idx)
            {
                cur1 = cur1->next;
            }
            else
            {
                if(acutal_length == length)
                    continue;
                Node* tmp = cur1->pre;
                Node* item = cur2;
                cur2 = cur2->next;
                link(tmp,item);
                link(item,cur1);
                cur1 = item;
                ++acutal_length;
            }
        }
        while (cur2 && acutal_length < length) {
            Node* newNode = new Node(cur2->data, cur2->idx);
            Node* last { };
            if (!Head) {
                Head = newNode;
                last = Head;
            } else {
                link(last, newNode);
                last = newNode;
            }
            cur2 = cur2->next;
            ++acutal_length;
        }
    }



};
