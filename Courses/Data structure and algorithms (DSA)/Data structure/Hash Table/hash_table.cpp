
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int hash_string (string str , int n)
{
    long long limit = n;
    long long sum {};
    for(auto &c : str)
        sum += (sum * 26 + c -'a') %limit;

    return sum % limit ;
}
struct phoneHashing{
    const static  int LIMIT = 1235679;
    string name{};
    string phone_number{};
    int hash()
    {
        return hash_string(name,LIMIT);
    }
    phoneHashing(string name, string phone_number):name(name), phone_number(phone_number){}
    void print()
    {
        cout<<"NAME : "<<name<<" "<<"Phone : "<<phone_number<<"\n";
    }
};
class hashtable{
private:
    int table_size{};
    vector<vector<phoneHashing>>table;
public:
    hashtable(int table_size):table_size(table_size)
    {table.resize(table_size);}

    void put(phoneHashing phone)
    {
        int idx  = phone.hash() % table_size;
        for(int i{0};i<(int)table[idx].size();++i)
        {
            if(table[idx][i].name == phone.name) {
                //table[idx][i] = phone; // update (optional)
                return;
            }
            table[idx].push_back(phone);
        }
    }

bool remove(phoneHashing  phone)
{
        int idx = phone.hash() % table_size;
        for(int i{0};i<(int)table[idx].size();++i)
        {
            if(table[idx][i].name == phone.name)
            {
                auto x = table[idx][i];
                auto y = table[idx].back();
                swap(x,y);
                table[idx].pop_back();
                return true;
            }
        }
    return false;
}
bool get(phoneHashing & phone)
{
        int idx = phone.hash() % table_size;
        for(int i{0};i<(int)table[idx].size();++i)
        {
            if(table[idx][i].name== phone.name)
                phone = table[idx][i];
            return true;
        }
    return false;
}
void print_all()
{
        for(int hash{0}; hash < table_size;++hash)
        {
            if(table[hash].size() == 0)
                continue;
            cout<<"hash : "<<hash<<" ";
            for(int i{0};i<(int)table[hash].size();++i)
            {
                table[hash][i].print();
            }
            cout<<"\n";
        }
}
};
