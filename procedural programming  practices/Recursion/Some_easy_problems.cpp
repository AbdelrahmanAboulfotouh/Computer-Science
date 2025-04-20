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
int arr_sum(int arr[], int len)
{
    if(len == 1)
        return arr[0];
    int sum_rest = arr_sum(arr,len-1);
    return arr[len-1] + sum_rest;
}
double arr_avarge(int arr[], int len)
{
    if(len == 1)
        return arr[0];
    double avarge_rest = arr_avarge(arr,len-1);
    double sum_rest = avarge_rest * (len-1);
    return  (sum_rest + arr[len-1]) / len;
}
double arr_avarge_using_helper(int arr[],int len)
{
    return arr_sum(arr,len)/(double)len;
}
void arr_increment(int arr[],int len)
{
    if(len == 1)
        return;
    arr[len-1]+=(len-1);
    arr_increment(arr,len-1);

}
void arr_accumulate(int arr[], int len)
{
    if(len == 1)
        return;
    arr_accumulate(arr,len-1);
    arr[len-1] = arr[len-1] + arr[len-2];
}


void Left_max(int arr[], int len)
{
    if(len == 1)
        return;
    Left_max(arr,len-1);
    arr[len-1] = max(arr[len-1] , arr[len-2]);
}
void right_max(int arr[], int len)
{
    if(len == 1) {
        return;
    }
    arr[len-2] = max(arr[len-2],arr[len-1]);
    right_max(arr,len-1);

}
void right_max(int len,int arr[])
{
    if(len == 1)
        return;
    right_max(len-1,arr+1);
    arr[0] = max(arr[0],arr[1]);
}
int suffix_sum(int arr[] , int len , int N){
    if(N == 0)
        return 0;
    auto rest = suffix_sum(arr,len-1,N-1);
    return arr[len-1] + rest;
}
int main()
{
    int arr[] = {1,3,5,7,4,2};
    cout<<suffix_sum(arr,6,6)<<"\n";

    //cout<<arr_sum(arr,5);
    //cout<<arr_max(arr,5);
    //cout<<my_pow(7,2);
    //cout<<length_3n_plus_one(10);
    return 0;
}