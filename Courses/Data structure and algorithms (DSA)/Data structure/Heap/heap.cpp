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

    void print_less_than(int val,int parent = 0)
    {
        if(parent == -1 or array[parent] >= val)
            return;
        cout<<array[parent]<<" ";
        print_less_than(val , left_child(parent));
        print_less_than(val, right_child(parent));
    }
    bool is_heap_array(int *p, int n,int parent = 0)
    {
        if(parent == -1)
            return true;
        int left = left_child(parent);
        int right = right_child(parent);
        if((left != -1 and p[parent] > p[left] )or (right and p[parent] < p[right]))
            return false;
        return is_heap_array(p,n, left_child(parent)) and is_heap_array(p,n, right_child(parent));
    }
    void heapfy()
    {
        for(int i =size/2-1;i>=0;--i)
        {
            heapify_down(i);
        }
    }
    void heap_sort(int *p, int n)
    {


    }
    ~heap()
    {
        delete array;
        array = nullptr;
    }
};
int main ()
{
    int vals[] ={2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30};
    heap h;
    h.heap_sort(vals,14);
    for(auto &x:vals)
        cout<<x<<" ";

    return 0;
}