/*The problem is to detect the expression is valid or not represented within the parenthesis i.e is there any irrelevant parenthesis is present*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	char temp;
	int open=0,close=0;
	cin>>str;
    stack<char> parenthesis;
    parenthesis.push('#');
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]==')')
        {
            if(parenthesis.top()=='(')
            {
                parenthesis.pop();
                continue;
            }
            if(parenthesis.top()=='#')
                open++;
        }
        if(str[i]=='(')
            parenthesis.push(str[i]);
    }
    while(!parenthesis.empty())
    {
        if(parenthesis.top()=='#')
        {
            parenthesis.pop();
            continue;
        }
        temp=parenthesis.top();
        parenthesis.pop();
        if(temp=='(')
            close++;
        else
            open++;
    }
    cout<<open<<" ( is needed\n";
    cout<<close<<" ) is needed\n";
}
