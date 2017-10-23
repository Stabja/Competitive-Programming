#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t ,m,n,k,i,j,d,a[100000];
    scanf("%lld",&t);
    while(t--)
    {  d=1;
       scanf("%lld",&n);
        for(i=0;i<n;++i)
        {
            scanf("%lld",&a[i]);
        }
        m=0;
        sort(a,a+n);
        for(i=0;i<n-1;++i)
        {
           if(a[i]==a[i+1])
           {
               d++;
           }
           else
           {
               if(d>m)
               {
                   m=d;
               }
               d=1;
           }
           if(d>m)
           {
               m=d;
           }
        }
        if(n%2!=0)
        {
            n++;
        }
        if(m<n/2)
            printf("%lld\n",n/2);
        else
            printf("%lld\n",m);
    }
    return 0;
}
