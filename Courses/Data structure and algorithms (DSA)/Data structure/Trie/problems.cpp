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
    string first_word_prefix(const string &str)
    {
        trie* cur = this;
        string ans;
        for(auto &c:str)
        {
            int cur_idx = c - 'a';
            ans+=c;
            if(cur->childs[cur_idx] == nullptr )
                break;
            cur = cur->childs[cur_idx];
            if(cur->is_leaf)
                return ans;
        }
        return str;
    }

};
class custom_trie{
    static const int MAX =26;
    custom_trie* childs[MAX];
    bool is_leaf{};
public:
    custom_trie()
    {
        memset(childs, 0, sizeof(childs));
    }
    void insert(string str )
    {
        custom_trie* cur = this;
        for(int i = str.size()-1;i>=0;--i)
        {
            int cu_idx = str[i] - 'a';
            if(cur->childs[cu_idx] == nullptr)
                cur->childs[cu_idx] = new custom_trie();
        }
        cur->is_leaf = true;
    }
    bool suffix_exist(string str)
    {
        custom_trie* cur = this;
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

class mapped_trie{
    map<char,mapped_trie*>childs;
    bool is_leaf{};
public:
    mapped_trie()
    {}
    void insert(string str )
    {
        mapped_trie* cur = this;
        for(auto &c:str)
        {
            if(cur->childs[c] == nullptr)
                cur->childs[c]= new mapped_trie();
            cur = cur->childs[c];
        }
        cur->is_leaf = true;
    }
    bool word_exisit(string str )
    {
        mapped_trie* cur = this;
        for(auto &c:str)
        {
            if(cur->childs[c] == nullptr)
                return false;
            cur = cur->childs[c];
        }
        return cur->is_leaf;
    }

    bool prefix_exisit(string str )
    {
        mapped_trie* cur = this;
        for(auto &c:str)
        {
            if(cur->childs[c] == nullptr)
                return false;
            cur = cur->childs[c];
        }
        return true;
    }
    string first_word_prefix(const string &str)
    {
        mapped_trie* cur = this;
        string ans;
        for(auto &c:str)
        {
            ans+=c;
            if(cur->childs[c] == nullptr )
                break;
            cur = cur->childs[c];
            if(cur->is_leaf)
                return ans;
        }
        return str;
    }

};

class trie_path {
    static const int MAX = 26;
    trie_path *childs[MAX];
    bool is_leaf{};
public:
    trie_path() {
        memset(childs, 0, sizeof(childs));
    }

    void insert(const vector<string> &path) {
        for(auto &str:path) {
            trie_path *cur = this;
            for (auto &c: str) {
                int cur_idx = c - 'a';
                if (cur->childs[cur_idx] == nullptr)
                    cur->childs[cur_idx] = new trie_path();
                cur = cur->childs[cur_idx];
            }
            cur->is_leaf = true;

        }
    }

    bool word_exisit(string str) {
        trie_path *cur = this;
        for (auto &c: str) {
            int cur_idx = c - 'a';
            if (cur->childs[cur_idx] == nullptr)
                return false;
            cur = cur->childs[cur_idx];
        }
        return cur->is_leaf;
    }

    bool subpath_exist(const vector<string> &path) {
        for(auto &str:path) {
            if(!word_exisit(str))
                return false;
        }
        return true;

    }
};

int main()
{
    trie_path tree;
    vector<string>path;
    path = {"home", "software", "eclipse"};
    tree.insert(path);
    path = {"home", "software", "eclipse", "bin"};
    tree.insert(path);
    path = {"home", "installed", "gnu"};
    tree.insert(path);
    path = {"user", "mostafa", "tmp"};
    tree.insert(path);

    path = {"user", "mostafa", "tmp"};
    cout << tree.subpath_exist(path) << "\n"; // 1
    path = {"user", "mostafa"};
    cout << tree.subpath_exist(path) << "\n"; // 1
    path = {"user", "most"};
    cout << tree.subpath_exist(path) << "\n"; // 0
    path = {"user", "mostafa", "private"};
    cout << tree.subpath_exist(path) << "\n"; // 0    return 0;
}