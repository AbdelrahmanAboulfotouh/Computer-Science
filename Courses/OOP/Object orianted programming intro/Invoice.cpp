#include "Invoice.h"
invoice::    invoice(string name, string item_number, double price , int quantity): name(name), item_number(item_number),price(price),quantity(quantity){}
void invoice::set_name(int name_)
{
    name = name_;
}
void invoice::set_item_number(int item_number)
{
    this->item_number = item_number;
}
void invoice::set_price(double price)
{
    this->price = price;
}
void invoice::set_quantity(int quantity_)
{
    quantity = quantity_;
}
string invoice::get_name()
{
    return name;
}
string invoice::get_item_number()
{
    return item_number ;
}
double invoice::get_price()
{
    return price;
}
int invoice::get_quantity()
{
    return  quantity ;
}
int invoice::Get_total_price()
{
    return (int) (get_price() * get_quantity());
}
void invoice::print()
{
    cout<<"Name: "<<get_name()<<" , "<<"Item_NO: "<<get_item_number()<<" , "<<"Price: "<<get_price()<<" , "<<get_quantity();
}
string invoice::To_string()
{
    string ans = name + item_number + to_string(price) + to_string(quantity);
    return ans;
}
