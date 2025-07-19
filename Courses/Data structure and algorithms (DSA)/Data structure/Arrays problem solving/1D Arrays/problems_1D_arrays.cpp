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
int main()
{
    int arr[] = {1,1,3,3,5,6};
    frequancy_the_array(arr,6);
    return 0;
}