#include <bits/stdc++.h>
using namespace std;
int count_unique_substrings(const string &str)
{
    unordered_set<string>S;
    for(int i{0};i<(int)str.size();++i)
        for(int len = i ; len < (int)str.size();++len)
            S.insert(str.substr(i,len - i +1));

    return S.size();

}
unordered_set<string> unique_substrings(const string &str)
{
    unordered_set<string>S;
    for(int i{0};i<(int)str.size();++i)
        for(int len = i ; len < (int)str.size();++len)
            S.insert(str.substr(i,len - i +1));

    return S;

}
int count_substrings_match(const string &str1, const string &str2)
{
    auto S1 = unique_substrings(str1);//O(N^2 * L)
    auto S2 = unique_substrings(str2);
    unordered_set<string> ans;
    for(auto &W1:S1)
        for(auto &W2:S2)
            if(W1 == W2)
                ans.insert(W1);
    return ans.size();
}

int count_anagram_substrings(const string &str)
{
    unordered_set<string>Set;
   for(int s{0};s<(int)str.size();++s)
       for(int e = s ; e<(int)str.size();++e)
       {
           string sub = str.substr(s,e-s+1);
           std::sort(sub.begin(), sub.end());
           Set.insert(sub);
       }
    return Set.size();
}
int main()
{
    string test1 = "aabade";
    string test2 = "xaaaaaaaaaaaaaaaaadvsfffffffffffffffffffffffffffffffffffffffffffffffffffffffddddddddddddddddeeeeeey";
    cout<<count_anagram_substrings(test1)<<"\n";
    return 0;
}