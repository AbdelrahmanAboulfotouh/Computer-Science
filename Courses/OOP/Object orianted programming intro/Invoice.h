#include <bits/stdc++.h>
using namespace std;
class invoice{
private:
    string name{};
    string item_number{};
    double price {};
    int quantity{};
public:
    invoice(string name, string item_number, double price , int quantity);
    void set_name(int name_);
    void set_item_number(int item_number);
    void set_price(double price);
    void set_quantity(int quantity_);
    string get_name();
    string get_item_number();
    double get_price();
    int get_quantity();
    int Get_total_price();
    void print();
    string To_string();

};