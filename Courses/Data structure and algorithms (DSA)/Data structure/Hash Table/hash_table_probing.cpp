#include <bits/stdc++.h>
using namespace std;

int hash_string (const string & str , const int &n)
{
    long long limit = n;
    long long  sum {};
    for(auto &c : str)
        sum = (sum * 26+( c -'a')) %limit;

    return sum % limit ;
}

int hash_string_extended (const string & str , const int & n)
{
    long long limit = n;
    long long sum {};
    int base = 62 ;//(2 * 26 + 10 )
    for(auto &c : str)
    {
        int val {0};
        if(islower(c))
            val = c - 'a';
        else if (isupper(c))
            val = 26 + (c - 'A');
        else if (isdigit(c))
            val = 26 + c - '0';
        sum = ((sum * base) + val) % limit;

    }

    return sum % limit ;
}

struct phoneHashing{
    const static  int LIMIT = 65407;
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

class HashTable{
private:
    int table_size{};
    vector<phoneHashing*>table;
    phoneHashing* deleted = new phoneHashing("","");
public:
    HashTable(int table_size):table_size(table_size){
        table.resize(table_size);
    }
    bool put(phoneHashing phone)
    {
        int idx = phone.hash() % table_size;
        for(int steps{0};steps < table_size;++steps)
        {
            if(table[idx]->name == phone.name) {
                table[idx]->phone_number = phone.phone_number;
                return true;
            }
            else if(table[idx] == deleted or table[idx] == nullptr) {
                table[idx] = new phoneHashing(phone.name, phone.phone_number);
                return true;
            }

            idx = (idx + 1 )% table_size;
        }
        return false;
    }

    bool remove(phoneHashing phone)
    {
        int idx = phone.hash() % table_size;
        for(int steps{0};steps < table_size;++steps)
        {
            if(table[idx] == nullptr)
                break;
            if(table[idx] != deleted and table[idx]->name == phone.name)
            {
                delete table[idx];
                table[idx] = deleted;
                return true;
            }


            idx = (idx + 1 )% table_size;
        }
        return false;
    }


    bool get(phoneHashing & phone)
    {
        int idx = phone.hash() % table_size;
        for(int steps{0};steps < table_size;++steps)
        {
            if(table[idx] == nullptr)
                break;
            if(table[idx] != deleted and table[idx]->name == phone.name)
            {
                phone.phone_number = table[idx]->phone_number;
                return true;
            }


            idx = (idx + 1 )% table_size;
        }
        return false;
    }
    void print_all()
    {
        for(int idx{0} ; idx < table_size ; ++idx)
        {
            if(table[idx] == deleted)
                cout<<'X';
            else if(table[idx] == nullptr)
                cout<<'E';
            else
                table[idx]->print();
            cout<<"\n";
        }
        cout<<"--------------------------------------------------------------------------------------------------------\n";
    }

};


