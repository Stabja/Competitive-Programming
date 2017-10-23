#include<bits/stdc++.h>
#include<algorithm>
typedef long long int ll;
using namespace std;

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

bool factor(int n, int t){
        ll sum = 1;
		for(int i=2;i<=(int)sqrt(n);i++) {
            int k = 0;
			while(n % i == 0) {
				printf("%d ",i);
				k++;
				n /= i;
			}
			sum *= 1LL*(k+1);
			k = 0;
		}
		if (n > 1){
            printf("%d\n",n);
            sum *= 1LL*2;
		}
		cout<<"\n"<<sum;
		if(sum == t)
            return true;
        return false;
}

int main(){
    factor(1500, 3);
    /*int a, b, n;
    a = read();
    b = read();
    n = read();
    ll cnt = 0;
    for(int i = a; i <= b; i++){
        if(factor(i, n))
            cnt++;
    }
    printf("%lld", cnt);*/
    return 0;
}
