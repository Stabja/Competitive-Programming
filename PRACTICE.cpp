#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define gc getchar
#else
	#define gc getchar_unlocked
#endif

int N, arr[101], P, Q, ans;

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

bool inrange(int x){
    if(x < P || x > Q)
        return false;
    else
        return true;
}

int main(){
    N = read();
    for(int i = 0; i < N; i++){
        arr[i] = read();
    }
    P = read();
    Q = read();
    int small = 1000000001;
    int large = 0;
    for(int i = 0; i < N; i++){
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }
    if(P <= small && Q <= small){
        cout<<P;
    }
    else if(P >= large && Q >= large){
        cout<<Q;
    }
    else{
        int ans = P;
        int val = 1000000001;
        int val2 = 1000000001;
        for(int i = 0; i < N; i++){
            val = min(val, abs(P - arr[i]));
        }
        for(int i = 0; i < N; i++){
            val2 = min(val2, abs(Q - arr[i]));
        }
        if(val2 > val){
            val = val2;
            ans = Q;
        }
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                int avg = (arr[i]+arr[j])/2;
                if(inrange(avg)){
                    int MaxMin = 1000000001;
                    for(int i = 0; i < N; i++){
                        MaxMin = min(MaxMin, abs(avg-arr[i]));
                    }
                    if(MaxMin > val){
                        val = MaxMin;
                        ans = avg;
                    }
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
