//
// Created by aboulfotouh on 5‏/10‏/2026.
//

#ifndef CPPARRAYLIST_NODE_H
#define CPPARRAYLIST_NODE_H



#include "Node.h"
#include <iostream>
using namespace  std;

class Node
{
public:

    int data;
    int index;
    Node* prev;
    Node* next;
    Node(int data, int index)
    {
        this->data = data;
        this->index = index;
        prev = nullptr;
        next = nullptr;
    }

};


#endif //CPPARRAYLIST_NODE_H
