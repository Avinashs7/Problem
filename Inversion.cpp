#include<bits/stdc++.h>
using namespace std;
int count(int a[],int i,int j,int n, int cnt[])
{
	if(j==n-1 && a[i]>a[j])
		return 1;
	else if(a[i]>a[j])
		return 1+cnt[j];
	else
		return count(a,i,j+1,n,cnt);
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	cin>>a[i];
	int cnt[n],c=0;
	cnt[n-1]=0;
	for(int i=n-2; i>=0; i--)
	{
		cnt[i]=count(a,i,i+1,n,cnt);
		c=c+cnt[i];
	}
	cout<<"The no of inversion formed\n";
	cout<<c<<endl;
}
