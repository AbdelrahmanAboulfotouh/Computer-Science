#include<bits/stdc++.h>
using namespace std;
class AVLTree{
private:
    struct Node{
        int data{};
        int hight{};
        Node* left{};
        Node* right{};
        Node(int data):data(data){};
    };
    Node* root{};
int child_hight(Node* node)
{
    if(!node)
        return -1;
    return node->hight;
}
void update_hight(Node* node)
{
    node->hight = 1 + max(child_hight(node->left), child_hight(node->right));
}
int get_hight(Node* node)
{
    return child_hight(node->left) - child_hight(node->right);
}
Node* left_rotation (Node* A)
{
    Node* B = A->right;
    A->right = B->left;
    B->left = A;

    update_hight(B);
    update_hight(A);
    return B;
}
Node* right_rotation(Node* B)
{
    Node* A = B->left;
    B->left = A->right;
    A->right = B;

    update_hight(A);
    update_hight(B);

    return A;
}
Node* balance (Node* node)
{
    if( get_hight(node)== 2)
    {
        if(get_hight(node->left) == -1)
        {
            left_rotation(node->right);
        }
        right_rotation(node);

    }
    else if(get_hight(node) == -2)
    {
        if(get_hight(node->right) == 1)
        {
            right_rotation(node->left);
        }
        left_rotation(node);


    }
    return node;
}
Node* insert_node(int val , Node* node)
{
    if(val < node->data)
    {
        if(!node->left)
            node->left = new Node(val);
        else
            insert_node(val,node->left);
    }
    else if (val >= node->data)
    {
        if(!node->right)
            node->right = new Node(val);
        else
            insert_node(val,node->right);
    }
    update_hight(node);
    return balance(node);
}
void insert_caller(int val)
{
    if(!root)
        root = new Node(val);
    else
        insert_node(val, root);
}
Node* min_node(Node* cur)
{
    while (cur and cur->left)
        cur = cur->left;
    return cur;
}
Node* delete_Node(int value,Node* node)
{
    Node* tmp =node;
    if(value < node->data)
        delete_Node(value, node->left);
    else if(value > node->data)
        delete_Node(value, node->right);
    else
    {
        if(!node->left and !node->right)
            node = nullptr;
        else if(!node->left)
            node = node->right;
        else if(!node->right)
            node = node->left;
        else
        {
            Node* MIN = min_node(node->right);
            node->data = MIN->data;
            node->right = delete_Node(node->data, node->right);
            tmp = nullptr;
        }
        if(tmp)
            delete tmp;
    }

    if(node) {
        update_hight(node);
        balance(node);
    }
    return node;
}
};