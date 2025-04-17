#include <bits/stdc++.h>
using namespace std;
class PirorityQueue{
    int Qlength{ };
    int Size{ };
    queue<pair<int,int>>q;
public:
    PirorityQueue(int Qlength):Qlength(Qlength){};
    void enqueu(int value, int prioriy)
    {
        if(Size == Qlength)
            return;
        pair<int,int> item = {value,prioriy};

        if(!Size)
            q.push(item);
        else
        {
            queue<pair<int,int>>tmp;

            bool placed = false;
            while (!q.empty()) {
                if(!placed and item.second>=q.front().second)
                {
                    tmp.push(item);
                    placed = true;
                }
                tmp.push(q.front());
                q.pop();
            }
            if(!placed)
                tmp.push(item);
            while (!tmp.empty())
                {
                    q.push(tmp.front());
                    tmp.pop();
                }

        }
        ++Size;
    }
    int dequeue()
    {
        auto Front = q.front();
        q.pop();
        --Size;
        return Front.first;

    }
    void display()
    {
        auto tmp = q;
        while (!tmp.empty()) {
            cout << tmp.front().first << "\n";
            tmp.pop();
        }
    }

};
int main()
{
    PirorityQueue tasks(10);
    tasks.enqueu(5000,3);

    tasks.enqueu(123,1);
    tasks.enqueu(7000,4);
    tasks.enqueu(2000,2);
    tasks.display();
    return 0;
}