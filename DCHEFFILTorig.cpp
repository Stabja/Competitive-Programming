#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,m,z,l,r,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>z>>l>>r>>b;
        long long int b1=min(b,((m+1)*n-l-r)/2);
        b1=min(b1,((m+1)/2)*n);
        cout<<min(l+r+z+b1,n*m)<<endl;
    }
    return 0;
}
