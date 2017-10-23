#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long int ll;
int main()
{
    ll t,ti,i;
    ll a[100001],b[100001];
    a[0]=0;
    b[0]=1;
    a[1]=2;
    b[1]=1;
    a[2]=3;
    b[2]=2;
    for(i=3;i<=100000;i++)
    {
        a[i]=(a[i-1]+a[i-2]+a[i-3])%mod;
        b[i]=(b[i-1]+b[i-2]+b[i-3])%mod;
    }
    cin>>t;
    while(t--)
    {
        cin>>ti;
        if(ti<=0)
            cout<<1<<" "<<0<<'\n';
        else
            cout<<a[ti-1]<<" "<<b[ti-1]<<'\n';
    }
    return 0;
}
