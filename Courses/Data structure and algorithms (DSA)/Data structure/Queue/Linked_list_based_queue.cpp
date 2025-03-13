#include <bits/stdc++.h>
#include "Singly_linked_list.h"
using namespace std;
class Queue{
    Linkedlist List ;
public:
    void Enqueue(int value)
    {
        List.insert_back(value);
    }
    int Dequeue()
    {
        return List.delete_front();
    }
    void print()
    {
        List.print();
    }
    bool isEmpty()
    {
        List.size() == 0;
    }
};
