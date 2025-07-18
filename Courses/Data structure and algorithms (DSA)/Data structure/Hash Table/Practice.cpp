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
int main()
{
    string test = "abcdef";
    cout<<count_unique_substrings(test);
    return 0;
}