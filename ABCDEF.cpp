#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX_N 101

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

int n,x[MAX_N],lo,hi;
long long res=0LL;
vector<int> m1, m2;

int main(){
    n = read();
    for(int i = 0; i < n; i++){
        x[i] = read();
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0;k < n; k++){
                m1.push_back(x[i]*x[j]+x[k]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            for(int k = 0; k < n; k++){
                if(x[k]==0)
                    continue;
                m2.push_back((x[i]+x[j])*x[k]);
            }
        }
    }
    sort(m1.begin(),m1.end());
    sort(m2.begin(),m2.end());
    for(int i = 0; i < m1.size(); i++){
        lo = lower_bound(m2.begin(),m2.end(),m1[i])-m2.begin();
        hi = upper_bound(m2.begin(),m2.end(),m1[i])-m2.begin();
        res += (hi-lo);
    }
    printf("%lld\n",res);
    return 0;
}
