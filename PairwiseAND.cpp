#include<bits/stdc++.h>

#ifndef ONLINE_JUDGE
	#define gc getchar
#else
	#define gc getchar_unlocked
#endif

int T[100004][40];

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

void computebinary(int k, int x){
    if(x == 0)
        return;
    int y = log2(x);
    T[k][y] = 1;
    if(y == 0)
        return;
    computebinary(k, x-pow(2, y));
}

int main(){
    int N, arr[100004];
    N = read();
    for(int i = 0; i < N; i++){
        arr[i] = read();
        computebinary(i, arr[i]);
    }
    long long int Total = 0;
    for(int j = 0; j < 40; j++){
        int sum = 0;
        for(int i = 0; i < N; i++){
            if(T[i][j] == 1)
                sum += 1;
        }
        Total += sum*1LL*(sum-1)*pow(2, j)/2;
    }
    printf("%lld", Total);
    return 0;
}
