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

int ar[100001], n, c;

int fnc(int x){
    int i,temp;
    temp=1;
    LL prev;
    prev=ar[0];
    for(i = 1; i < n; i++){
        if(ar[i]-prev>=x){
            temp++;
            if(temp==c)
                return 1;
            prev=ar[i];
        }
    }
    return 0;
}

void binsearch(){
    int l,r,mid;
    l=0;
    r=ar[n-1];
    while(l<r){
        mid=(l+r)/2;
        if(fnc(mid)==1)
            l=mid+1;
        else
            r=mid;
    }
    cout<<l-1<<"\n";
}

int main(){
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int t;
    t=read();
    while(t--){
        n=read();
        c=read();
        for(int i = 0; i < n; i++)
            ar[i]=read();
        sort(ar,ar+n);
        binsearch();
    }
    return 0;
}







