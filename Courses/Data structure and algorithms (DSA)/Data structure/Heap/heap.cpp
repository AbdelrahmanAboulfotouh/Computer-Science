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
    int parent(int child){};
    int left_child(int node){
        int pos = 2*node +1 ;
        return pos >=size ? -1 : pos;
    };
    int right_child(int node){
        int pos = 2*node+2;
        return pos >= size ? -1 : pos ;
    };
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
    ~heap()
    {
        delete array;
        array = nullptr;
    }
};