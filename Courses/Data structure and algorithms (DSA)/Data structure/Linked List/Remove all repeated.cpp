#include "LinkedList.cpp"
int main()
{

Linkedlist x;

x.insert_back(1);
x.insert_back(2);
x.insert_back(2);
x.insert_back(2);
x.insert_back(3);

/*
x.insert_back(1);
x.insert_back(1);
x.insert_back(2);
x.insert_back(2);
x.insert_back(2);
x.insert_back(3);
x.insert_back(5);
*/
x.print();
x.Remove_all_repeated();
x.print();
    return 0;
}