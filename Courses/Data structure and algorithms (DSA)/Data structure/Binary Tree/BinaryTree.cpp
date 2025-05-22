#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data{ };
    Node* left{ };
    Node* right{ };
    Node(int data):data(data){};
};
struct BinaryTree {
    Node* root { };
    BinaryTree(int root_value) :
            root(new Node(root_value)) {
    }

    void add(vector<int> values, vector<char> direction) {
        assert(values.size() == direction.size());
        Node* current = this->root;
        // iterate on the path, create all necessary TreeNodes
        for (int i = 0; i < (int) values.size(); ++i) {
            if (direction[i] == 'L') {
                if (!current->left)
                    current->left = new Node(values[i]);
                else
                    assert(current->left->data == values[i]);
                current = current->left;
            } else {
                if (!current->right)
                    current->right = new Node(values[i]);
                else
                    assert(current->right->data == values[i]);
                current = current->right;
            }
        }
    }

    void _print_inorder(Node* current) {
        if (!current)
            return;
        _print_inorder(current->left);
        cout << current->data << " ";
        _print_inorder(current->right);
    }


    void print_inorder() {
        _print_inorder(root);
        cout << "\n";
    }

};

void print(Node* cur)
{
    if(cur == nullptr)
        return;
    print(cur->left);
    print(cur->right);
    cout<<cur->data<<"  ";

}
bool is_leaf(Node* N)
{
    return  N and N->left == nullptr and N->right == nullptr;
}
bool is_complete(Node* N)
{
    if(!N)
        return true;
    return N->left and N->right;
}
bool is_Full(Node* root)
{
    if(!root)
        return false;
    return (is_leaf(root) or is_complete(root) ) and is_Full(root->left) and is_Full(root->right);

}
int Tree_max(Node* root)
{
    if(!root)
        return INT16_MIN;
    int MAX = root->data;
    int right_max = Tree_max(root->right);
    int left_max = Tree_max(root->left);
    MAX = max({MAX,left_max,right_max});

    return MAX;
}
int Tree_nodes_counter(Node* root)
{
    if(!root)
        return 0;
    auto left_nodes = Tree_nodes_counter(root->left);
    auto right_nodes = Tree_nodes_counter(root->right);
    return left_nodes + right_nodes + 1;
}
int Tree_sum(Node* root)
{
    if(!root)
        return 0;
    int sum = root->data + Tree_sum(root->left) + Tree_sum(root->right);
    return sum;
}
bool is_perfect(Node* root)
{
    if(!root)
        return false;
    if(!is_leaf(root) and Tree_nodes_counter(root->left) == Tree_nodes_counter(root->right))
        return true;
    return is_perfect(root->right) and is_perfect(root->left);
}
void level_order_traversal(Node* root)
{
    queue<Node*> nodes;
    nodes.push(root);
    int level {0};
    while (!nodes.empty())
    {
        int sz = nodes.size();
        while (sz--)
        {
            auto cur = nodes.front();
            nodes.pop();
            cout<<cur->data;
            if(cur->left)
                nodes.push(cur->left);
            if(cur->right)
                nodes.push(cur->right);
        }
         level++;
    }
}
void BST_insertion(Node* root,int value)
{
    if(value == root->data)
        return;
    if(value < root->data)
    {
        if(root->left)
            BST_insertion(root->left,value);
        else
        {
            auto item = new Node(value);
            root->left = item;
            return;
        }
    }
    if(value > root->data)
    {
        if(root->right)
            BST_insertion(root->right,value);
        else
        {
            auto item = new Node(value);
            root->right = item;
            return;
        }
    }

}
int BSR_min(Node* root)
{
    if(!root->left)
        return root->data;
    return BSR_min(root->left);
}
void helper(int stars,int spaces)
{
    if(!spaces)
        return;
    int sp = spaces/2;
    int s = stars;
    while (sp--)
        cout<<" ";
    while (s--)
        cout<<'*';
    cout<<endl;
    return helper(stars +1,spaces-1);


}
void genrate_pyramid(int stars)
{
    helper(1,stars);
}
struct Dnode{
    Dnode* next{ };
    Dnode*pre  { };
    int val{ };;
    Dnode(int val): val(val){};
};
Dnode* build(Node* treeroot)
{
    if(!treeroot)
        return { };
    Dnode* mid = new Dnode(treeroot->data);
    Dnode*  Left = build(treeroot->left);
    Dnode* Right = build(treeroot->right);
    mid->next = Right;
    Right->next = Left;
    Left->next = mid;
    mid->pre = Left;
    Left->pre = Right;
    Right->pre = mid;
    return Left;
}
Node* min_value(Node* root)
{
    if(!root)
        return nullptr;
    if(!root->left)
        return root;
    return min_value(root->left);
}
bool find_chain(Node* root, int target, vector<Node*>&anscestors)
{
    anscestors.push_back(root);
    if(root->data == target)
        return true;
    if(root->left)
        find_chain(root->left,target,anscestors);
    return root->right and find_chain(root->right,target,anscestors);
}
Node* get_next(vector<Node*>&anscestors)
{
    if(!anscestors.size())
        return nullptr;
    Node* cur = anscestors.back();
    anscestors.pop_back();
    return cur;
}

pair<bool,int> successor(Node* root,int target)
{
    vector<Node*>anscestors;
    if(!find_chain(root,target,anscestors))
        return {false,-1};
    Node* child = get_next(anscestors);
    if(child->right)
        return make_pair(true, min_value(root->left)->data);
    auto parent = get_next(anscestors);
    while (parent and parent->right == child)
    {
        child = parent;
        parent = get_next(anscestors);
    }
    if(parent)
        return {true,parent->data};
    return {false, -1};
}
int main() {
    genrate_pyramid(5);
    // 7 4 8 2 5 9 1 3 10 6

    return 0;
}
