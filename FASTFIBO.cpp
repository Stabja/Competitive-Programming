#include <map>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 60
#define MAXM 4
#define M 1000000007

long long F[MAXN][MAXM],FB[MAXN+5];

#ifndef ONLINE_JUDGE
	#define gc getchar
#else
	#define gc getchar_unlocked
#endif

void readint(long long &a){
    register int c;
    a = 0;
    do{
        c = gc();
    }while(c < '0');
    do{
        a = (a << 1) + (a << 3) + c - '0';
        c = gc();
    }while(c >= '0');
}

void printint(long long int a)
{
    char s[21];
    int t = -1;
    do{
        s[++t] = a % 10 + '0';
        a /= 10;
    }while(a > 0);
    while(t >= 0)putchar(s[t--]);
        putchar('\n');
}

long long int mulmod(long long int a,long long int b) {
    long double res = a;
    res *= b;
    long long int c = (long long)(res / M);
    a *= b;
    a -= c * M;
    a %= M;
    if (a < 0) a += M;
    return a;
}
long long int  f(long long int  n,int depth = 0 ) {
    if(n<=MAXN){
        return FB[n]%M ;
    }
    int val = n%4 ;
    if (F[depth][val] != -1)
        return F[depth][val];
    long long int  k=n >> 1;
    long long int a,b,c;
    a = f(k,depth+1) ;
    b = f(k-1,depth+1) ;
    if (n%2==0) {
        F[depth][val] = (mulmod(a,a) + mulmod(b,b));
    }else {
        c = f(k+1,depth+1) ;
        F[depth][val] = (mulmod(a,c) + mulmod(b,a));
    }
    if(F[depth][val] >= M)
        F[depth][val] -= M ;
    return F[depth][val] ;
}

int main(){
    long long int T;
    readint(T);
    FB[0] = 0 ;
    FB[1] = 1 ;
    for(int i=2; i <= 64; i++){
        FB[i] = FB[i-1] + FB[i-2] ;
    }
    while(T--){
        long long int Z, N;
        memset(F,-1,sizeof F);
        readint(Z);
        readint(N);
        long long int ans = 0;
        ans = (f(N+2)%M-f(Z+1)%M)%M;
        printint(ans);
    }
    return 0 ;
}
