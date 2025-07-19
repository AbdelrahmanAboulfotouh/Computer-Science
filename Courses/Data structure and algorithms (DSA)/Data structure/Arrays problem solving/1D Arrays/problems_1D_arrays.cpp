#include <bits/stdc++.h>
using namespace std;

pair<int,int> first_two_max(int arr[],int n)
{
    int max1 = INT16_MIN;int idx1{-1};
    int max2 = INT16_MIN;
    for(int i{0};i<n;++i)
    {
        max1 = max(max1, arr[i]);
        if (max1 == arr[i])
            idx1 = i;
    }

    for(int i{0};i<n;++i)
        if(i != idx1)
            max2 = max(max2,arr[i]);
    return {max1,max2};

}
int find_max_sum_of_pair(int arr[],int n)
{
    auto p = first_two_max(arr,n);
    return p.first + p.second;
}
void reverse_in_place(int * arr,int n)
{
    int l{0},r = n-1;
    while (l<r)
    {
        swap(arr[l],arr[r]);
        l++,r--;
    }
}
void frequancy_the_array(int arr[],int n)
{
    map<int,int>fr;
    for(int i{0};i<n;++i)
        fr[arr[i]]++;
    for(auto & F:fr)
        cout<<F.first<<" Repeated: "<<F.second<<"\n";
}
bool is_increasing(int arr[],int n)
{
    for(int i{1};i<n;++i)
        if(arr[i] <= arr[i-1])
            return false;
    return true;
}
void Replace_min_max(int *arr,int n )
{
    int Max = INT32_MIN;
    int Min = INT32_MAX;
    for(int i{0};i<n;++i)
    {
        Max= max(Max,arr[i]);
        Min = min(Min,arr[i]);
    }
    for(int i{0};i<n;++i)
    {
        if(arr[i] == Max)
        {
            arr[i] = Min;
            continue;
        }
        if(arr[i] == Min)
        {
            arr[i] = Max;
            continue;
        }
    }

}
vector<int> unique_numbers_orderd()
{
    int n;
    cin>>n;
    int x{-1},y{-1};
    bool f = false;
    vector<int>list;
    while (n--)
    {
        if(!f) {
            cin >> x;
            f = true;
            continue;
        }
        cin>>y;
        if(x != y )
        {
            if(n == 0)
            {
                list.push_back(y);
                continue;
            }
            list.push_back(x);
            x = y;
        }


    }
    return list;
}
bool is_palindrome(int arr[],int n)
{
    for(int i{0};i<=n/2;++i)
        if(arr[i] != arr[n-1-i])
            return false;
    return true;
}
int minimum_pair_equation(int arr[],int n)
{
    int ans = INT32_MAX;
    for(int i{0};i<n-1;++i)
    {
        for(int j = i + 1 ; j< n ; ++j)
        {
            int tmp = arr[i] + arr[j] + j-i;
            ans = min(ans,tmp);

        }
    }
    return ans;
}
int main()
{
    int arr[] = {20,1,9,4};
    cout<<minimum_pair_equation(arr,4);
    return 0;
}