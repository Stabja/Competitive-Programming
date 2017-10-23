#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    long long int n, x, cnt[100000], f[100000];
    //scanf("%I64d", &n);
    cin>>n;
    for(long long int i = 0; i < n; i++){
        //scanf("%I64d", &x);
        cin>>x;
        cnt[x]++;
    }
    f[0] = 0;
    f[1] = cnt[1];
    for(long long int i = 2; i <= n; i++){
        f[i] = max(f[i-1], f[i-2] + i*cnt[i]);
    }
    printf("%I64d", f[n]);
    return 0;
}
