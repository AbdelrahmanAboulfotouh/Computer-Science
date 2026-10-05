//
// Created by aboulfotouh on 5‏/10‏/2026.
//

#ifndef CPPARRAYLIST_ARRAYLIST_H
#define CPPARRAYLIST_ARRAYLIST_H

#include "ArrayList.h"
#include "Node.h"
#include <iostream>
#include <unistd.h>
using namespace std;

class ArrayList
{
public:

    int length;
    int size;
    Node* Head;
    ArrayList(int length)
    {
        size = 0;
        this->length = length;
        Head= nullptr;
    }
    void link(Node* first, Node* second,bool middle)
    {
        Node* first_next = nullptr;
        if (first != nullptr)
        {
            first_next = first->next;
            first->next = second;

        }

        if (second != nullptr)
        {
            second->prev = first;
        }
        if (middle)
        {
            if (second)
                second->next = first_next;
            if (first_next)
                first_next->prev = second;
        }


    }
    Node* search_first_lest_idex(int idx)
    {
        Node* previous = nullptr;
        for (Node* cur = Head ; cur ; cur = cur->next)
        {
            if (cur->index <= idx)
                previous =  cur;
        }
        return previous;
    }
    void set_value(int val, int index)
    {
        if (size == length)
        {
            cout<<"No enough space ";
            return;
        }
        Node* newNode = new Node(val,index);
        size++;
        if (Head == nullptr)
        {
            Head = newNode;
        }
        else
        {
            Node* pervious = search_first_lest_idex(index);
            bool is_middle =false;

            if (pervious == nullptr)
            {
                link(newNode , Head,is_middle);
                Head = newNode;
            }
            else
            {
                if (pervious->next)
                    is_middle =true;
                link(pervious,newNode,is_middle);
            }




        }
    }
    void print_arry_non_zero()
    {
        for (Node* cur = Head ; cur ; cur=cur->next)
        {
            cout<<cur->data<<" ";
        }
    }
    void print_arry()
    {
        int idx =0;
        for (Node* cur = Head ; cur ; cur = cur->next)
        {
            while (idx < cur->index)
            {
                cout<<"0"<<" ";
                ++idx;
            }
            if (cur->index == idx)
            {
                cout<<cur->data<<" ";
                ++idx;
            }

        }
        while (idx <this->length)
        {
            cout<<"0"<<" ";
            ++idx;
        }
    }
    Node* search_by_index(int idx)
    {
        for (Node* cur = Head ;cur;cur = cur->next)
        {
            if (cur->index ==idx )
                return cur;
        }
        return nullptr;
    }
    void add (ArrayList arry)
    {
        for (Node* cur = arry.Head ;cur;cur = cur->next )
        {
            Node* wanted_node = this->search_by_index(cur->index);
          if (wanted_node)
          {
              wanted_node->data=( wanted_node->data + cur->data);
          }
            else
                this->set_value(cur->data,cur->index);

        }


    }
};
#endif //CPPARRAYLIST_ARRAYLIST_H
