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
    ArrayLinkedList(int length):length(length){};
    void set_value(int value, int index)
    {
        if(length == acutal_length)
            return;
        ++acutal_length;
        Node* new_item = new Node(value,index);
        if(!Head) {
            Head = new_item;
            return;
        }
        for(auto cur = Head;cur;cur=cur->next)
        {
            if(cur->idx >= new_item->idx)
            {
                if(Head == cur)
                    Head = new_item;
                Node*tmp = cur->pre;
                link(new_item,cur);
                link(tmp,new_item);
                break;
            }
            else if(cur->idx < new_item->idx)
            {
                bool f = false;
                 if(cur->next == nullptr)
                     f = true;
                 else if(cur->next->idx > new_item->idx)
                         f = true;
                 if(f)
                 {

                     Node *tmp = cur->next;
                     link(cur, new_item);
                     link(new_item, tmp);
                     break;
                 }

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
    Node* get(int index)
    {
        for(auto cur = Head; cur ; cur = cur->next)
        {
            if(cur->idx == index)
                return cur;
        }
        return { };
    }
    void add(ArrayLinkedList List2)
    {
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
int main()
{
    ArrayLinkedList List(10);
    List.set_value(50,5);
    List.set_value(20,2);
    List.set_value(70,7);
    List.set_value(40,4);
    //List.print_array_nonzero();
    List.print();
/*
    ArrayLinkedList List2(10);
    List2.set_value(1,4);
    List2.set_value(3,7);
    List2.set_value(4,6);
    List2.print_array_nonzero();
    List.add(List2);
    List.print();
*/
    return 0;
}