#include <iostream>
#include <queue>
using namespace std ;

class Sum_of_last_K_numbers{
    int size{ };
    int K{ };
    queue<int>q;
    int sum{ };
public:
    Sum_of_last_K_numbers(int K):K(K){};
    int get_sum(int new_num)
    {
        if(++size > K)
        {
            sum-=q.front();
            q.pop();
            --size;
        }
        q.push(new_num);
        sum+=new_num;
        return sum;
    }


};
int main()
{
    Sum_of_last_K_numbers process(4);
    int num;
    while (cin>>num)
        cout<<process.get_sum(num);
    return 0;
}