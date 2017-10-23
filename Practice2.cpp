#include<bits/stdc++.h>
using namespace std;

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

long arr[100005];
pair<int, int> preSum[100005];
map<int, int> freq;

int BinSearch(int l, int r, int item, bool isLow){
        int mid = (l+r)/2;
        if(preSum[mid].second == item){
            if(isLow)
                return preSum[mid-1].first;
            else
                return preSum[mid].first;
        }
        else if(preSum[mid].second < item && preSum[mid+1].second > item){
            return preSum[mid].first;
        }
        else if(item > preSum[mid].second){
            l = mid+1;
            return BinSearch(mid+1, r, item, isLow);
        }
        else if(item < preSum[mid].second){
            r = mid-1;
            return BinSearch(l, mid-1, item, isLow);
        }
}

void debug(int k){
    for(int i = 0; i < k; i++){
        cout<<preSum[i].first<<" ";
    }
    cout<<endl;
    for(int i = 0; i < k; i++){
        cout<<preSum[i].second<<" ";
    }
    cout<<"\n"<<k<<"\n";
}

int main(){
    int n;
    n = read();
    for(int i = 0; i < n; i++){
        arr[i] = read();
    }
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    map<int, int>::iterator it;
    int k = 1;
    for(it = freq.begin(); it != freq.end(); ++it){
        if(k == 0){
            preSum[k++].first = (*it).second;
            preSum[k-1].second = (*it).first;
        }
        else{
            preSum[k++].first = preSum[k-2].first + (*it).second;
            preSum[k-1].second = (*it).first;
        }
    }
    //debug(k);
    int q;
    q = read();
    while(q--){
        int ll, rr;
        ll = read();
        rr = read();
        if(ll > preSum[k-1].second)
            ll = preSum[k-1].second;
        if(rr > preSum[k-1].second)
            rr = preSum[k-1].second;
        int x = BinSearch(0, k-1, ll, true);
        int y = BinSearch(0, k-1, rr, false);
        cout<<y-x<<"\n";
    }
    return 0;
}
