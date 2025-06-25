#include <bits/stdc++.h>
using namespace std;
class heap{
private:
    int* array;
    int size;
    int capacity{1000};
public:

    heap(){
        array = new int[capacity];
        size = 0;
    }
    int parent(int child){
        return floor((child-1)/2);
    }
    int left_child(int node){
        int pos = 2*node +1 ;
        return pos >=size ? -1 : pos;
    }
    int right_child(int node){
        int pos = 2*node+2;
        return pos >= size ? -1 : pos ;
    }
    void push(int val){
        assert(size+1 <= capacity);
        array[size++] = val;
        heapfy_up(size-1);
    }
    void heapfy_up(int child){
        int parent_id = parent(child);
        if(parent_id == 0 or array[parent_id] <= array[child])
            return;
        swap(array[parent_id],array[child]);
        heapfy_up(parent_id);
    }
    int top()
    {
        assert(size > 0);
        return array[0];
    }
    void heapify_down(int parent_idx)
    {
        int Child = left_child(parent_idx);
        int Right_child = right_child(parent_idx);
        if(Child == -1)
            return;
        if(Child != -1 and array[Child] > array[Right_child])
            Child = Right_child;
        if(array[parent_idx] > array[Child])
        {
            swap(array[parent_idx],array[Child]);
            heapify_down(Child);

        }
    }
    void pop()
    {
        assert(size > 0);
        array[0] = array[--size];
        heapify_down(0);
    }
    bool is_empty()
    {
        return size == 0;
    }
    void get_less_than(int val , vector<int> &v, int idx = 0)
    {
        if(idx == -1)
            return;

        int ch1 = left_child(idx);
        if(array[ch1] < val)
        {
            v.push_back(array[ch1]);
            get_less_than(val , v,ch1);
        }
        int ch2 = right_child(idx);
        if(array[ch2] < val)
        {
            v.push_back(array[ch2]);
            get_less_than(val , v,ch2);
        }
    }
    vector<int>print_less_than(int val)
    {
        vector<int>ans;
        if(array[0] < val)
        {
            ans.push_back(array[0]);
            get_less_than(val,ans,0);
        }

        return ans;
    }
    ~heap()
    {
        delete array;
        array = nullptr;
    }
};
int main ()
{
    vector<int>vals ={2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30};
    heap h;
    for(auto  &x:vals)
        h.push(x);
    vector ans = h.print_less_than(10);
    for(auto &c :ans)
        cout<<c<<" ";


    return 0;
}