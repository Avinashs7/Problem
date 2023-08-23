#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int open=0;
	for(int i=0; i<str.length();i++)
	{
		 if(str[i]==')' && open!=0)
			open--;
		if(str[i]=='(')
			open++;
	}
	cout<<open<<endl;
}
