/*The number of inversions formed in an array. Inversion is formed when i<j and a[i]>a[j] */
#include<bits/stdc++.h>
using namespace std;
/*int count(int a[],int i,int j,int n, int cnt[])
{
	if(j==n-1 && a[i]>a[j])
		return 1;
	else if(a[i]>a[j])
		return 1+cnt[j];
	else
		return count(a,i,j+1,n,cnt);
}*/
/* Above recursive calls may solve the problem using DP but it takes more space to copy every time in recursive calls and DP using recursive calls is known as MEMOIZATION
   and if it is done in iterative approach then it takes less number of space and optimal solution and method is known as TABULATION*/
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
		for(int j=i+1; j<n; j++)
		{
			if(a[i]>a[j]){
				cnt[i]+=1+cnt[j];
				break;
			}
		}
		c+=cnt[i];
		/*cnt[i]=count(a,i,i+1,n,cnt);
		c=c+cnt[i];*/
	}
	cout<<"The number of inversion formed\n";
	cout<<c<<endl;
}
