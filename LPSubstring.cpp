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

int pass[1005];
int cnt[1002][1002];

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

int main(){
    int t;
    t = read();
    while(t--){
        int n, m, s;
        n = read();
        m = read();
        s = read();
        for(int i = 1; i <= m; i++){
            pass[i] = read();
        }
        cnt[s][1] = 1;
        for(int j = 1; j < m+2; j++){
            for(int i = 1; i < n+1; i++){
                if((i-pass[j]) >= 1){
                    cnt[i-pass[j]][j+1] = (cnt[i-pass[j]][j+1]%MAXX + cnt[i][j]%MAXX)%MAXX;
                }
                if((i+pass[j]) <= n){
                    cnt[i+pass[j]][j+1] = (cnt[i+pass[j]][j+1]%MAXX + cnt[i][j]%MAXX)%MAXX;
                }
            }
        }
        for(int i = 1; i < n+1; i++){
            cout<<cnt[i][m+1]<<" ";
        }
        cout<<"\n";
        memset(cnt, 0, sizeof cnt);
        memset(pass, 0, sizeof pass);
    }
    return 0;
}
