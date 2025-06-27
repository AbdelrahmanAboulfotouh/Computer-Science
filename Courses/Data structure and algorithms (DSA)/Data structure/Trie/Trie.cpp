#include<bits/stdc++.h>
using namespace std;
class trie{
    static const int MAX =26;
    trie* childs[MAX];
    bool is_leaf{};
public:
    trie()
    {
        memset(childs, 0, sizeof(childs));
    }
    void insert(string str, int idx )
    {
        if(idx == (int) str.size())
            is_leaf = true;
        else
        {
            int cur_idx = str[idx] - 'a';
            if(childs[cur_idx] == nullptr)
                childs[cur_idx] = new trie();
            childs[cur_idx]->insert(str, idx+1);
        }
    }
    bool word_exisit(string str ,int idx = 0)
    {
        if(idx == (int) str.size())
            return is_leaf;
        int cur_idx = str[idx] - 'a';
        if(childs[cur_idx] == nullptr)
            return false;
        word_exisit(str, idx + 1);
    }

    bool prefix_exisit(string str ,int idx = 0)
    {
        if(idx == (int) str.size())
            return true;
        int cur_idx = str[idx] - 'a';
        if(childs[cur_idx] == nullptr)
            return false;
        prefix_exisit(str, idx + 1);
    }


};