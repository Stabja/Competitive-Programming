#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define MAXX 1000000007

#ifndef ONLINE_JUDGE
	#define gc getchar
#else
	#define gc getchar_unlocked
#endif

inline int read(){
	int res = 0,sign = 1;
	char c = gc();
	while(!(c>='0' && c<='9')){
		if(c=='-')
		sign = -1;
		c = gc();
	}
	while(c>='0' && c<='9'){
		res = (res<<3)+(res<<1)+c-'0';
		c = gc();
	}
	return res*sign;
}

LL pow_mod(LL a, LL b, LL m){       //Modular Exponentiation
    LL x = 1, y = a;                //a^b%m
    while(b > 0){
        if(b & 1)
            x = (x*y)%m;
        y = (y*y)%m;
        b>>=1;
    }
    return x;
}

int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
  {
     int n,i;
     scanf("%d",&n);
     long long int ans=1;
     for(i=0;i<n-1;i++)
        ans=ans<<1;
     ans=ans*(n*(n+1))/2;
     printf("%lld\n",ans);
   }
   return 0;
}

