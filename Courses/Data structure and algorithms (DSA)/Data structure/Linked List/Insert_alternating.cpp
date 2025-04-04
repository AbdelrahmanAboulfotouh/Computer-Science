#include "LinkedList.cpp"
Node* insert_alternate(Node* list, Node* another)
{
    Node* Head{ };

    if(list)
        Head = list;
    else if(another)
        Head = another;
    Node* alis = Head;
    Node* cur1=list;
    Node* cur2=another;
    bool T = true;
    while (cur1 && cur2)
    {
        if(T )
        {
            alis->next = cur2;
            cur2 = cur2->next;
            T = !T;
        }
        else
        {
            alis->next = cur1;
            cur1 = cur1->next;
            T = !T;
        }
        if(alis)
            alis = alis->next;

    }
    if(cur1)
        alis->next =cur1;
    else
        alis->next =cur2;

    return Head;
}
int main()
{


    Linkedlist list1;
    list1.insert_back(1);
    list1.insert_back(2);
    Linkedlist list2;
    list2.insert_back(4);
    list2.insert_back(5);
    Node* head1 = list1.get_head();
    Node* head2 = list2.get_head();
    Node* head = insert_alternate(head1,head2);
for(auto cur = head;cur ;cur =cur->next)
{
    cout<<cur->data;
}

    return 0;
}