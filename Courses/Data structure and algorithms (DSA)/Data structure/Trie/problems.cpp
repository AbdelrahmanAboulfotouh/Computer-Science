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
int main() {
    trie root;

    root.insert("xyz");
    root.insert("xyzea");
    root.insert("a");
    root.insert("bc");

    cout << root.first_word_prefix("xyzabc") << "\n"; // Output: xyz
    cout << root.first_word_prefix("x") << "\n";      // Output: x
    cout << root.first_word_prefix("xyzeab") << "\n"; // Output: xyzea
    cout << root.first_word_prefix("abc") << "\n";    // Output: a
    cout << root.first_word_prefix("bcdef") << "\n";  // Output: bc
    cout << root.first_word_prefix("zzz") << "\n";    // Output: zzz

    return 0;
}