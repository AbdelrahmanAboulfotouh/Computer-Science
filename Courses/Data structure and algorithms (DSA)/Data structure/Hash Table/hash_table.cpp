
#include <bits/stdc++.h>
#include <algorithm>
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
struct someobject{
    static const int LIMIT = 214789564;
    string name1, name2;
    int number;

    int hash()
    {
        long long res = hash_string_extended(name1,LIMIT);
        res += hash_string_extended(name2,LIMIT) %LIMIT;
        res += hash_string_extended(to_string(number),LIMIT)%LIMIT;
        return res;
    }
};

class hashtable{
private:
    int table_size{};
    int Total_elements{};
    double limit_load_factor{};
    vector<vector<phoneHashing>>table;
public:
    hashtable(int table_size = 10, double limit_load_factor = 0.75):table_size(table_size)
    {
        table.resize(table_size);
        this->limit_load_factor = limit_load_factor;
            Rehash();

    }
    void Rehash()
    {
        double cur_load = Total_elements / table_size;
        if(cur_load  < (double) limit_load_factor)
            return;
        hashtable new_table(table_size *2 , limit_load_factor);
        for(int idx{0} ; idx < (int)table_size; ++idx)
        {
            if(table[idx].size() == 0)
                continue;
            for(auto & object:table[idx])
                new_table.put(object);

        }
        table_size*=2;
        table = new_table.table;


    }

    void put(phoneHashing phone)
    {
        int idx  = phone.hash() % table_size;
        for(int i{0};i<(int)table[idx].size();++i)
        {
            if(table[idx][i].name == phone.name) {
                table[idx][i] = phone; // update (optional)
                return;
            }
        }
        table[idx].push_back(phone);
        ++Total_elements;
        Rehash();

    }

bool remove(phoneHashing  phone)
{
        int idx = phone.hash() % table_size;
        for(int i{0};i<(int)table[idx].size();++i)
        {
            if(table[idx][i].name == phone.name)
            {
                swap(table[idx][i], table[idx].back());
                table[idx].pop_back();
                --Total_elements;
                return true;
            }
        }
    return false;
}
bool get(phoneHashing & phone)
{
        int idx = phone.hash() % table_size;
    for (auto &entry : table[idx]) {
        if (entry.name == phone.name) {
            phone = entry;
            return true;
        }
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

int main() {


    return 0;
}
