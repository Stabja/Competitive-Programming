#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,n) for(int i=a;i<n;i++)
#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PI 3.141592653589

vector<pair<int, int> > vec;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.se > b.se;
}

int main(){
    int x, y;
    cin>>x>>y;
    int p, q;
    for(int i = 0; i < y; i++){
        cin>>p>>q;
        vec.pb(mp(p, q));
    }
    sort(vec.begin(), vec.end(), compare);
    int cnt = x;
    LL mc = 0;
    for(int i = 0; i < y; i++){
        if(cnt <= 0){
            break;
        }
        if(cnt >= vec[i].fi){
            mc += 1LL*vec[i].fi*vec[i].se;
            cnt -= vec[i].fi;
        }
        else{
            mc += 1LL*cnt*vec[i].se;
            cnt = 0;
        }
    }
    cout<<mc;
    return 0;
}
