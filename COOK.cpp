#include<bits/stdc++.h>
using namespace std;

#define MAXX 32001
bool primes[32001];
int prime[10000];

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

void sieve(){
    for(int i = 2; i*i <= MAXX; i++){
        if(!primes[i]){
            for(int j = 2*i; j <= MAXX; j+=i){
                primes[j] = true;
            }
        }
    }
    int z = 0;
    for(int i = 2; i < MAXX; i++){
        if(!primes[i]){
            prime[z++] = i;
        }
    }
}

int main(){
    sieve();
    /*for(int i = 0; i < 30; i++){
        cout<<prime[i]<<" ";
    }*/
    int a, b, n;
    a = read();
    b = read();
    n = read();
    int cnt2 = 0;
    for(int i = a; i <= b; i++){
        long long int total = 1;
        int k = i;
        int x = 0;
        for(int j = prime[x]; j <= (int)sqrt(k); j = prime[++x]){
            int cnt = 0;
            while(k%j == 0){
                cnt++;
                k /= j;
            }
            total *= (cnt+1);
        }
        if(k!=1)
            total*=2;
        //cout<<total<<" ";
        if(total == n)
            cnt2++;
    }
    printf("%d", cnt2);
    return 0;
}
