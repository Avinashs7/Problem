#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],hash[n+1]={0};
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]>0 && a[i]<=n)
            hash[a[i]]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(hash[i]==0)
        {
            cout<<i<<" is the least positive number missing\n";
            break;
        }
    }

}
