#include "heap.cpp"
class max_heap
{
private:
    heap min_heap;
public:
    void insert(int val)
    {
        min_heap.push( -val);
    }
    void pop()
    {
        min_heap.pop();
    }
    int top()
    {
        return -min_heap.top();
    }
    bool is_empty()
    {
        return min_heap.is_empty();
    }
};