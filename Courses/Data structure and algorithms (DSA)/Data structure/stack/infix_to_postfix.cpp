#include<bits/stdc++.h>
using namespace std;
int precedence (char op)
{
    if(op == '+' or op == '-')
        return 1;
    if(op == '*' or op == '/')
        return 2;
    return 0;
}
string infixToPostix(string &infix)
{
    stack<char> operators;
    string postfix ;
    for(int i{0};i<(int)infix.size();++i) {
        if (isdigit(infix[i]))
        {
            postfix+=infix[i];
        }
        else
        {
            while (!operators.empty() and precedence(operators.top()) >= precedence(infix[i]) )
            {
                postfix+=operators.top();
                operators.pop();

            }
            operators.push(infix[i]);
        }
    }
    while (!operators.empty())
    {postfix+=operators.top() , operators.pop();}

    return postfix;
    
}
int main()
{
    string infinx = "1+3*5-8/2";
cout<<infixToPostix(infinx);
    return 0;
}
