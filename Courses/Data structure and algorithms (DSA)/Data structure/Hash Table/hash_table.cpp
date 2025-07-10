
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int hash_string (string str , int n)
{
    long long limit = n;
    long long sum {};
    for(auto &c : str)
        sum = (sum * 26 +( c -'a')) %limit;

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
        }
        table[idx].push_back(phone);

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

    hashtable table(3);
    table.put(phoneHashing("mostafa", "604-401-120"));
    table.put(phoneHashing("mostafa", "604-401-777"));	// update
    table.put(phoneHashing("ali", "604-401-343"));
    table.put(phoneHashing("ziad", "604-401-17"));
    table.put(phoneHashing("hany", "604-401-758"));
    table.put(phoneHashing("belal", "604-401-550"));
    table.put(phoneHashing("john", "604-401-223"));

    phoneHashing e("mostafa", "");
    if (table.get(e))
        cout << e.phone_number << "\n";	// 604-401-777

    table.print_all();
    // Hash 0: (ali, 604-401-343)  (hany, 604-401-758)  (john, 604-401-223)
    // Hash 1: (mostafa, 604-401-777)  (ziad, 604-401-17)
    // Hash 2: (belal, 604-401-550)

    cout << table.remove(phoneHashing("smith", "")) << "\n"; // 0
    cout << table.remove(phoneHashing("hany", "")) << "\n";  // 1
    cout << table.remove(phoneHashing("belal", "")) << "\n";  // 1
    table.print_all();
    // Hash 0: (ali, 604-401-343)  (john, 604-401-223)
    // Hash 1: (mostafa, 604-401-777)  (ziad, 604-401-17)


    return 0;
}
