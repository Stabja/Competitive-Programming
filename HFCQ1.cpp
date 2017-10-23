#include <bits/stdc++.h>
using namespace std;
int check[100001];
int prime[100001];
void shieve()
{
    for(int i=3;i<=18000;i+=2)
    {
        if(!check[i])
        {
            for(int j=i*i;j<=32000;j+=i)
                check[j]=1;
        }
    }
    prime[0] = 2;
    int j=1;
    for(int i=3;i<=32000;i+=2)
    {
        if(!check[i]){
            prime[j++]=i;
        }
    }
}

int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    shieve();
    int a,b,n,temp,total=1,res=0;
    scanf("%d", &n);
    int count=0,i,j,k;
    //for(i=a;i<=b;i++)
    //{
    temp=n;
    total=1;
    k=0;
    for(j=prime[k];j*j<=temp;j=prime[++k])
    {
            count=0;
            while(temp%j==0)
            {
                count++;
                temp/=j;
            }
            total *=count+1;
    }
    if(temp!=1)
        total*=2;
        /*if(total==n)
            res++;*/
    //}
    printf("%d\n", total);
    return 0;
}
