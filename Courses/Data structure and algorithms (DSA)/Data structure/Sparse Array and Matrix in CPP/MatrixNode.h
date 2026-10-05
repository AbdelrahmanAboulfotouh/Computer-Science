//
// Created by aboulfotouh on 5‏/10‏/2026.
//

#ifndef CPPARRAYLIST_MATRIXNODE_H
#define CPPARRAYLIST_MATRIXNODE_H

#include "ArrayList.h"
#include "Node.h"
#include <iostream>
using namespace std;

class MatrixNode
{
public:
    ArrayList* subList;
    int index;
    MatrixNode* prev;
    MatrixNode* next;

    MatrixNode(int size,int index)
    {
        this->subList  = new ArrayList(size);
        this->index = index;
        this->prev =nullptr;
        this->next =nullptr;
    }

};


#endif //CPPARRAYLIST_MATRIXNODE_H
