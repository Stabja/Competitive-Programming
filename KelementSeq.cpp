#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair


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

LL dp[2000005];

void calcFact(){
    for(int i = 1; i < 2000001; i++){
        dp[i] = (i%MAXX*dp[i-1]%MAXX)%MAXX;
    }
}

LL power(LL x, LL y, LL p){                //Inverse using modular exponentiation
    LL res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;

        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

LL gcdExtended(LL a, LL b, LL *x, LL *y){     //Inverse using Extended Eucledian
    if(a == 0){
        *x = 0, *y = 1;
        return b;
    }
    LL x1, y1;
    LL gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
LL modInverse(LL a, LL m){
    LL x, y;
    LL g = gcdExtended(a, m, &x, &y);
    LL res = (x%m + m) % m;
    return res;
}

int main(){
    dp[0] = 1;
    calcFact();
    //cout<<dp[4]<<" "<<dp[5]<<"\n";
    int t;
    t = read();
    while(t--){
        int n, r;
        n = read();
        r = read();
        n--;
        r--;
        LL num = dp[n];
        LL den1 = dp[r];
        LL den2 = dp[n-r];
        LL inv1 = power(den1, MAXX-2, MAXX);
        LL inv2 = power(den2, MAXX-2, MAXX);
        LL ans = (num%MAXX*inv1%MAXX*inv2%MAXX)%MAXX;
        cout<<ans<<"\n";
    }
    return 0;
}
