#include<bits/stdc++.h>
#include<algorithm>

#define MAXX 1000000007

#ifndef ONLINE_JUDGE
	#define gc getchar
#else
	#define gc getchar_unlocked
#endif

inline int read(){
	char c = gc();
	int num = 0;
	while(!(c>='0' && c<='9'))
	c = gc();

	while(c>='0' && c<='9'){
		num = (num<<3)+(num<<1)+c-'0';
		c = gc();
	}
	return num;
}


int main(){
    int T, N, x;
    long long int M, arr[100005];
    T = read();
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%lld", &N, &x, &M);
        for(int i = 0; i < N; i++){
            scanf("%lld", &arr[i]);
        }
        while(M--){
            for(int i = 1; i < x; i++){
                arr[i] = arr[i]+arr[i-1];
            }
        }
        printf("%lld\n", arr[x-1]%MAXX);
    }
    return 0;
}
