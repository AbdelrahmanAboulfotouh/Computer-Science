
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
    void print()
    {
        for(Node* cur = Head;cur;cur=cur->next)
            cout<<cur->data<<" ";
        cout<<endl;
    }
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
        ++Length;
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
        ++Length;
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
void delete_all_nodes_with_key(int key)
{
    insert_front(-key);
        for(Node* cur = Head ; cur ; cur = cur->next)
        {
            if(cur->data == key)
            {
                cur = delete_and_link(cur);
                if(!cur->next)
                    Tail = cur ;
            }
            else
                cur  = cur->next;
        }
        delete_front();
}
void delete_even_positions()
{
        for(Node* cur = Head ; cur and cur->next ; cur=cur->next)
        {
            delete_and_link(cur->next);
            if(!cur->next)
                Tail = cur;
        }
}
void delete_odd_positions()
{
    insert_front(0);
    delete_even_positions();
    delete_front();
}
bool is_balindrome()
{
        int len  = Length/2 ;
        for(auto  front = Head , back = Tail; len-- ; front = front->next , back = back->pre)
        {

            if(front->data != back->data)
                return false;

        }
    return true;
}
int find_middle()
{
        int ans{ };
        for(auto ltr = Head, rtl = Tail; rtl ; rtl = rtl->pre, ltr = ltr->next)
        {
            if(ltr->next == rtl or rtl == ltr)
                ans = rtl->data;

        }
    return ans;
}
int find_middle_with_sll()
{
    auto cur1 = Head , cur2 = Head;
    for(; cur2 and cur2->next ; cur1 = cur1->next , cur2=cur1->next);

   return cur1->data;
}
void Swap_forward_with_backward(int k)
{
        int s = Length-k+1;
        if(k == s)
            return;
        if(k > s)
            swap(s,k);
        Node* swa{ };
        Node* swb{ };
        int c{1};

    for(auto cur = Head ; cur ; cur = cur->next)
    {
        if(c == k)
            swa = cur;
        if(c == s)
            swb = cur;
        if(swa and swb)
            break;
        ++c;
    }
    auto Preb = swb->pre;
    auto Nextb = swb->next;

    auto Prea = swa->pre;
    auto Nexta = swa->next;


    bool F =(Preb == swa or  Prea == swb or Nexta == swb or Nextb == swa);

    if(swa == Head and swb == Tail or (swa == Tail and swb == Head))
        swap(Head,Tail);
    link(Preb,swa);
    link(swa,Nextb);

    link(Prea,swb);
    link(swb,Nexta);
    if(F)
        link(swb,swa);


}
};
int main ()
{
    DoulbyLinkedlist List;
    List.insert_back(1);
    List.insert_back(2);

    List.insert_back(3);
    List.insert_back(4);
    List.insert_back(5);
    List.insert_back(6);

    List.print();
    List.Swap_forward_with_backward(6);
    List.print();
    return 0;
}