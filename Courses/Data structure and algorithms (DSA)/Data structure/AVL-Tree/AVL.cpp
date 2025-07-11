#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class AVLTree {
private:
    struct BinaryNode {
        int data { };
        int height { };
        BinaryNode* left { };
        BinaryNode* right { };

        BinaryNode(int data) :
                data(data) {
        }

        int ch_height(BinaryNode* node) {	// child height
            if (!node)
                return -1;			// -1 for null
            return node->height;	// 0 for leaf
        }
        int update_height() {	// call in end of insert function
            return height = 1 + max(ch_height(left), ch_height(right));
        }
        int balance_factor() {
            return ch_height(left) - ch_height(right);
        }
    };

    BinaryNode *root { };

    ///////////////////////////


    BinaryNode* right_rotation(BinaryNode* Q) {
        BinaryNode* P = Q->left;
        Q->left = P->right;
        P->right = Q;
        Q->update_height();
        P->update_height();
        return P;
    }

    BinaryNode* left_rotation(BinaryNode* P) {
        BinaryNode* Q = P->right;
        P->right = Q->left;
        Q->left = P;
        P->update_height();
        Q->update_height();
        return Q;
    }

    BinaryNode* balance(BinaryNode* node)
    {
        if (node->balance_factor() == 2) { 			// Left
            if (node->left->balance_factor() == -1)	// Left Right?
                node->left = left_rotation(node->left);	// To Left Left

            node = right_rotation(node);	// Balance Left Left
        } else if (node->balance_factor() == -2) {
            if (node->right->balance_factor() == 1)
                node->right = right_rotation(node->right);

            node = left_rotation(node);
        }
        return node;
    }

    BinaryNode* insert_node(int target, BinaryNode* node) {
        if (target < node->data) {
            if (!node->left)
                node->left = new BinaryNode(target);
            else
                // change left. update left as it might be balanced
                node->left = insert_node(target, node->left);
        } else if (target > node->data) {
            if (!node->right)
                node->right = new BinaryNode(target);
            else
                node->right = insert_node(target, node->right);
        }
        node->update_height();
        return balance(node);
    }

    BinaryNode* min_node(BinaryNode* cur) {
        while (cur && cur->left)
            cur = cur->left;
        return cur;
    }

    BinaryNode* delete_node(int target, BinaryNode* node) {
        if (!node)
            return nullptr;

        if (target < node->data)
            node->left = delete_node(target, node->left);
        else if (target > node->data)
            node->right = delete_node(target, node->right);
        else {
            BinaryNode* tmp = node;

            if (!node->left && !node->right)	// case 1: no child
                node = nullptr;
            else if (!node->right) 	// case 2: has left only
                node = node->left;		// connect with child
            else if (!node->left)	// case 2: has right only
                node = node->right;
            else {	// 2 children: Use successor
                BinaryNode* mn = min_node(node->right);
                node->data = mn->data;	// copy & go delete
                node->right = delete_node(node->data, node->right);
                tmp = nullptr;	// Don't delete me. Successor will be deleted
            }
            if (tmp)
                delete tmp;
        }
        if (node) {
            node->update_height();
            node = balance(node);
        }
        return node;
    }


void lower_bound(int target, int &ans, BinaryNode* cur )
{
        if(!cur)
            return ;

        if (cur->data >= target)
            {
                ans = min(ans, cur->data);
                lower_bound(target,ans,cur->left);
            }
        else
             lower_bound(target,ans,cur->right);

}

    void upper_bound(int target, int &ans, BinaryNode* cur )
    {
        if(!cur)
            return ;

        if (cur->data > target)
        {
            ans = min(ans, cur->data);
            upper_bound(target,ans,cur->left);
        }
        else
            upper_bound(target,ans,cur->right);

    }
    int count_bigger(int val,BinaryNode* node)
    {
        if(!node)
            return 0;
        if(node->data > val)
            return  1 + count_bigger(val , node->left) + count_bigger(val , node->right);

        return count_bigger(val,node->right);
    }
public:
    void insert_value(int target) {
        if (!root)
            root = new BinaryNode(target);
        else
            root = insert_node(target, root);
    }

    void delete_value(int target) {
        if (root) {
            root = delete_node(target, root);
        }
    }

    pair<bool, int> lower_bound(int target)
    {

        if(root)
        {

        int ans  = INT32_MAX;
        lower_bound(target, ans, root);
        if (ans != INT32_MAX and ans >= target)
            return {true, ans};

        }
        return {false, -1};

    }
    pair<bool, int> upper_bound(int target)
    {
        if(root)
        {

            int ans  = INT32_MAX;
            upper_bound(target, ans, root);
            if (ans != INT32_MAX and ans > target)
                return {true, ans};

        }
        return {false, -1};
    }

    int count_inversion(vector<int> v)
    {
        int sum {0};

        for(auto & i:v)
        {
            insert_value(i);
            cout<<i<<" "<<count_bigger(i,root)<<"\n";
            sum+= count_bigger(i,root);
        }
        return sum;
    }
};

int main() {
    AVLTree tree;

    vector<int> v { 10, 5, 8, 2, 12, 6 };
    //vector<int> v { 5, 4, 3, 2, 1};
    cout << tree.count_inversion(v);

    cout << "\nbye\n";

    return 0;
}

