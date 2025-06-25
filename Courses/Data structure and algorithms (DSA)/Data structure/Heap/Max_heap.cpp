#include <bits/stdc++.h>
using namespace std;

class max_heap{
private:
    int *arr{};
    int size{};
    int capcity{200};
public:
    max_heap()
    {
        arr = new int[capcity];
        size = 0;
    }
    int top()
    {
        assert(size >=0);
        return arr[0];
    }
    int get_size()
    {
        return size;
    }
    void heapfy_up(int child_pos)
    {
        int parent_pos = floor((child_pos-1)/2);
        if(parent_pos <=0 or arr[child_pos] <= arr[parent_pos])
            return;
        swap(arr[child_pos],arr[parent_pos]);
        heapfy_up(parent_pos);
    }
    void insert(int val)
    {
        if(size>= capcity) {
            capcity *= 2;
            arr = new int[capcity];
        }
        arr[size] = val;
        heapfy_up(size);
        size++;
    }
    void heapfy_down(int parent_pos)
    {
        int child1_pos = parent_pos*2 +1;
        int child2_pos = parent_pos*2 + 2;
        if(child1_pos == -1)
            return;
        if(arr[child2_pos] > arr[child1_pos])
        {
            child1_pos = child2_pos;

        }
        if(child1_pos != -1 and arr[child1_pos] > arr[parent_pos])
            swap(arr[parent_pos],arr[child1_pos]);
        heapfy_down(child1_pos);

    }
    void delete_()
    {
        arr[0] = arr[--size];
        heapfy_down(0);
    }
    ~max_heap()
    {
        delete arr;
        arr = nullptr;
    }
};
