#include "Max_heap.cpp"
class kth_smallest_number{
    int k;
    max_heap h ;
public:
    kth_smallest_number(int k):k(k){};
    int next(int val){
       if(k > h.get_size())
           h.insert(val);
       else if (val < h.top())
       {
           h.delete_();
           h.insert(val);
       }
           return h.top();
    }
};
int main()
{
    kth_smallest_number process(4);
    int num;
    while (cin>>num)
        cout<<process.next(num);
    return 0;
}