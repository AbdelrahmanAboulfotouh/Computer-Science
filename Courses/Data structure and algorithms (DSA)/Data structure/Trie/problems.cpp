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
    void insert(string str )
    {
        trie* cur = this;
       for(auto &c:str)
       {
           int cur_idx = c - 'a';
           if(cur->childs[cur_idx] == nullptr)
               cur->childs[cur_idx]= new trie();
           cur = cur->childs[cur_idx];
       }
       cur->is_leaf = true;
    }
    bool word_exisit(string str )
    {
        trie* cur = this;
        for(auto &c:str)
        {
            int cur_idx = c - 'a';
            if(cur->childs[cur_idx] == nullptr)
                return false;
            cur = cur->childs[cur_idx];
        }
        return cur->is_leaf;
    }

    bool prefix_exisit(string str )
    {
        trie* cur = this;
        for(auto &c:str)
        {
            int cur_idx = c - 'a';
            if(cur->childs[cur_idx] == nullptr)
                return false;
            cur = cur->childs[cur_idx];
        }
        return true;
    }


};
