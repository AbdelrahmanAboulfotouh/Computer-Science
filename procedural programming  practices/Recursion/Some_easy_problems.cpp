#include <iostream>
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
int main()
{
    cout<<length_3n_plus_one(10);
    return 0;
}