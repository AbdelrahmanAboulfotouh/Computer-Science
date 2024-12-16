#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
struct Node{
    int data{};
    Node* next{};
    //Node(int data) : data(data){};
    Node(int data)
    {
        this->data =data;
    }

};

class Linkedlist{
private:
    Node* Head{};
    Node* tail{};
    int lenght;
public:
    void print(){
        for(Node* current = Head; current ; current = current->next )
        {
            cout<<current->data<<" ";
        }
        cout<<endl;
    }
    void insert_back(int value)
    {
        Node* newnode = new Node(value);
        if(Head == nullptr)
            Head = tail = newnode;
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    //time o(n), space o(1)
    Node* get_nth(int n)
    {
        int count{};
        for(Node* current = Head ; current ; current = current->next,++count)
        {
            if(count == n)
                return current;
        }
        return nullptr;
    }

    int search(int value)
    {
        int index{};
        for(Node* current = Head ; current ; current = current->next,++index)
        {
            if(current->data == value)
                return index;
        }
        return -1;
    }
    int search_improved(int value)
    {
        int index{};
        Node* pre{};
        for(Node* current = Head ; current ; pre = current,current = current->next,++index)
        {
            if(current->data == value)
            {
                if(pre)
                {
                    swap(current->data,pre->data);
                    return index-1;
                }
                else
                    return index;
            }
        }
        return -1;
    }

    //#1 time O(N), space o(1)
    ~Linkedlist()
    {
        while (Head)
        {
            Node* current =Head;
            Head = Head->next;
            delete current;
        }
    }

    //#2(easy) time O(1), space O(1)
    void inser_front( int value)
    {
        Node* newnode = new Node(value);
        newnode->next = Head;
        Head = newnode;
        ++lenght;
        if(lenght == 1)
            tail =Head;
    }

    //#3(easy) time o(1) , space o(1)
    void delete_front()
    {
        if(!Head)
            return;
        if(lenght > 1)
        {
            Node* current = Head;
            Head = Head->next;
            delete current;
        }
        else
        {
            delete Head;
            delete tail;
            Head = nullptr;
            tail = nullptr;
        }
        --lenght;
    }

    //#4(easy) time o(n), space o(1)
    Node* get_nth_back(int idx)
    {
        assert(idx <= lenght and idx>=1);
        return get_nth(lenght - idx +1);

    }
 
    //#5(easy) time o(n) space o(1)
    bool is_same(const Linkedlist &other)
    {
        if(lenght != other.lenght)
            return false;
        Node* curr = Head;
        for(Node* cur = other.Head; cur and curr ;cur = cur->next,curr =curr->next)
        {
            if(cur->data != curr->data)
                return false;
        }
        return true;
    }

    //#5 (easy) time o(n) space o(1)
    bool is_same_with_no_lenght(const Linkedlist &other)
    {

        Node* curr = Head;
        for(Node* cur = other.Head; cur and curr ;cur = cur->next,curr =curr->next)
        {
            if((cur->next == nullptr and curr->next != nullptr) or (curr->next == nullptr and cur->next != nullptr))
                return false;
            if(cur->data != curr->data)
                return false;
        }
        return true;
    }



};
//#6 (easy)  LinkedList with only a Head pointer
class LinkedList{
private:
    Node* Head;
public:
    // time O(n) space o(1)
    void print(){
        for(Node* cur = Head;cur; cur = cur->next)
        {
            cout<<cur->data;
        }
    }
//time o(1) space o(1)
    void add_element(int value)
    {
        Node* newnode = new Node(value);
        newnode->next = Head;
        Head = newnode;
    }
    Node* get_tail()
    {
        if(!Head)
            return nullptr;
        for(Node* cur =Head; cur ; cur = cur->next)
            if(cur->next == nullptr)
                return cur;
    }

};
