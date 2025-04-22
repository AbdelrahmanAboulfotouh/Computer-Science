#include <iostream>
using namespace std;
struct Node{
    int data{ };
    Node* left{ };
    Node* right{ };
    Node(int data):data(data){};
};
void print(Node* cur)
{
    if(cur == nullptr)
        return;
    print(cur->left);
    print(cur->right);
    cout<<cur->data<<"  ";

}