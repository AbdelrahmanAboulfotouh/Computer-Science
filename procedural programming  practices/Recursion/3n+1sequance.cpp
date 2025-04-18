#include <iostream>
using namespace std;

void generate_sequnce(int n)
{
    cout << n << " ";

    if (n == 1)
        return;

    if(n % 2 == 0)
        generate_sequnce(n/2);
    else
        generate_sequnce(3*n +1 );

}
int main()
{
    generate_sequnce(7);
    return 0;
}
