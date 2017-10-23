#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

pair<LL, LL> tree[100005];
LL n, w, l, p;

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

LL compute(LL t){
    p = w;
    for(int i = 0; i < n; i++)
    {
        LL val=(l-tree[i].first-1)/tree[i].second;
        val++;
        if(val < 0){
            val = 0;
        }
        if(val <= t)
        {
            p -= tree[i].first;
            p -= t*tree[i].second;
        }
        if(p <= 0)
           break;
    }
}

LL binSearch(LL l, LL h){
    LL mid;
    while(l < h){
        mid = (l+h)/2;
        LL temp = compute(mid);
        if(p > 0)
            l = mid+1;
        else if(p < 0)
            h = mid;
        else{
            break;
        }
    }
    if(mid < l)
        cout<<l;
    else
        cout<<mid;
}

int main(){
    cin>>n>>w>>l;
    for(int i = 0; i < n; i++){
        cin>>tree[i].first>>tree[i].second;
    }
    binSearch(0, 1000000000000000000);
    return 0;
}
