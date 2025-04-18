#include <iostream>
#include <algorithm>
using namespace std;

int length_3n_plus_one(int N)
{
    if(N == 1)
        return 1;
    if(N % 2 == 0)
        return length_3n_plus_one(N/2) +1;
    else
        return length_3n_plus_one(3*N + 1)+1;

}
int my_pow(int value,int p = 2)
{
    if(p == 0)
        return 1;
    return value * my_pow(value,p-1);
}
int arr_max(int arr[],int len)
{
    if(len == 1)
        return arr[0];
    int max_of_rest = arr_max(arr,len-1);
    return max(arr[len-1],max_of_rest);
}
int main()
{
    //int arr[] = {1,8,2,10,3};
    //cout<<arr_max(arr,5);
    //cout<<my_pow(7,2);
    //cout<<length_3n_plus_one(10);
    return 0;
}