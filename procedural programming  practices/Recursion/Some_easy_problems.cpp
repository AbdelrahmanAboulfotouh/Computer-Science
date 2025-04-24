#include <iostream>
#include <cmath>
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
int prefix_sum(int arr[],int N)
{
    if(N == 0)
        return 0;
    auto rest = prefix_sum(arr+1,N-1);
    return arr[0] + rest;
}
bool is_palindrome(int arr[],int len) {
    if (len <= 1)
        return true;
    return (*arr == arr[len - 1]) and is_palindrome(arr + 1, len - 2);
}
    bool non_recursive_is_prefix(string str,string word)
    {
        string sub = str.substr(0,word.size());
        return sub == word;

    }
    bool recursive_is_prefix(string str, string word, int pos)
    {
        if(pos == word.size())
            return true;
        return str[pos] == word[pos] and recursive_is_prefix(str,word,pos+1);
    }
    bool is_prime(int n , int s =2)
    {

        if(n < 2 )
            return false;
        if(s >= sqrt(n))
        {
            if(n % s == 0)
                return false;
            else
                return true;
        }
        return (n % s != 0) and is_prime(n,s+1);
    }
int count_primes(int start, int end)
{
    if(start > end)
        return 0;
    return (int)is_prime(start) + count_primes(start+1,end);
}
int grid_sum(int grid[100][100],int row, int col, int rows, int columns){
    if(row >= rows or  col >= columns)
        return 0;
    int x { }, y{ };
    int right{ }, down{ },diagonal{ };
    if(row+1 < rows)
        right =grid[row+1][col]  ;
    if(col+1 < columns)
        down =grid[row][col+1] ;
    if(col+1  < columns and row+1 < columns)
     diagonal =grid[row+1][col+1];

    if(right>=down and right >= diagonal )
        x = 1;
    else if (down >= right and down >= diagonal)
        y = 1;
    else
        {x = 1 , y= 1;}



    return grid[row][col] + grid_sum(grid,row+x,col+y,rows,columns);
}
long long fibonacci(int n){
    if(n <= 1)
        return 1;
    long long y = fibonacci(n-2);
    long long x = fibonacci(n-1) ;

    return x +y;
}
int main()
{
    int x,y;cin>>x>>y;
    int arr[100][100];
    for(int i{0}; i< x ; ++i)
        for(int j{0};j<y;++j)
        {
            cin>>arr[i][j];
        }
    cout<<grid_sum(arr,0,0,x,y);
   // cout<<fibonacci(6);
    //cout<<count_primes(10,200000);
    //cout<<recursive_is_prefix("abcde","abcde",0);

    //int arr[] = {1,0};
    //cout<<is_palindrome(arr,2)<<"\n";

    //cout<<arr_sum(arr,5);
    //cout<<arr_max(arr,5);
    //cout<<my_pow(7,2);
    //cout<<length_3n_plus_one(10);
    return 0;
}