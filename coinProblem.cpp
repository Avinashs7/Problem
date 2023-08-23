#include<bits/stdc++.h>
using namespace std;
void changeMore(float denom[2][5],float change)
{
    int x[5];
    for(int i=0;i<5;i++)
        x[i]=0;
    float amount=0;
    for(int i=0,j=i-1; i<5; )
    {
        if(denom[1][0]==1 && change-amount==change-int(amount))
            i++;
        if(denom[1][i]==0)
        {
            i++;
            continue;
        }
        while(amount<change)
        {
            if(denom[1][i]==0)
                break;
            amount+=denom[0][i];
            denom[1][i]--;
            x[i]++;
        }
        while(amount>change && j!=-1)
        {
            if(x[j]!=0)
            {
                amount-=denom[0][j];
                x[j]--;
                denom[1][j]++;
            }
            else
            {
                j--;
            }
        }
        j=i-1;
        if(amount==change)
            break;
    }
    cout<<"Amount: "<<amount<<endl;
    cout<<"The change returned with maximum coin is\n";
    for(int i=0; i<5; i++)
    {
        if(x[i]==0)
            continue;
        cout<<denom[0][i]<<" is "<<x[i]<<"\n";
    }
}
void changeLess(float denom[2][5],float change)
{
    int x[5];
    for(int i=0;i<5;i++)
        x[i]=0;
    float amount=0;
    for(int i=4; i>=0; )
    {
        if(denom[1][i]==0 || amount+denom[0][i]>change)
        {
            i--;
            continue;
        }
        amount=amount+denom[0][i];
        denom[1][i]--;
        x[i]++;
    }
    cout<<"Amount: "<<amount<<endl;
    cout<<"The change returned with minimum coin is\n";
    for(int i=0; i<5; i++)
    {
        if(x[i]==0)
            continue;
        cout<<denom[0][i]<<" is "<<x[i]<<"\n";
    }
}
int main()
{
    float denom[2][5]={{0.5,1,5,10,50},{0,0,0,0,0}},change=0;
    string op; 
    cout<<"Enter the change needs to be returned\n";
    cin>>change;
    cout<<"Enter the denomination available\n";
    for(int i=0; i<5; i++){
        cout<<"Enter the no of "<<denom[0][i];
        if(i<=1)
            cout<<" rupee coins\n";
        else
            cout<<" rupee notes\n";
        cin>>denom[1][i];
    }
    cout<<"Enter whether you want to recieve more number of coins or in less number \n";
    cin>>op;
    if(op=="less")
        changeLess(denom,change);
    else if("more")
        changeMore(denom,change);
}