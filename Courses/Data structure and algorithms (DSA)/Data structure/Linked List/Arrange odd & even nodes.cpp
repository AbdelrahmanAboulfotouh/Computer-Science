#include "LinkedList.cpp"
Node* arrangelist(Node* list)
{
    Node* evenHead{ };
    Node* alis = evenHead;
    Node* tmp{ };
    Node* Last { };
    for(Node* cur = list;cur;cur=cur->next)
    {

         tmp = cur->next;
        if(!evenHead)
        {
            evenHead = tmp;
            alis =evenHead;
        }
        else
        {
            if(alis)
                alis->next = tmp;
            alis = alis->next;
        }
            if(cur->next)
                cur->next = tmp->next;
        if(!cur->next) {
            cur->next = evenHead;
            break;
        }
    }

    return list;
}

int main()
{
    Linkedlist list ;
    list.insert_back(1);
    list.insert_back(2);
    list.insert_back(3);

    arrangelist(list.get_head());
    list.print();

    list.insert_back(4);
    list.insert_back(5);
    list.insert_back(6);
    list.insert_back(7);
    //list.print();

    return 0;
}
