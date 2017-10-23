#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000009
#define LL long long int
#define mp make_pair
#define pb push_back

LL ans = 0;

void recurse(LL c, int k, LL s, int m, int d){
    if(c > s){
        return;
    }
    if(c == s){
        ans = (ans%MOD + 1)%MOD;
        return;
    }
    for(int i = 1; i <= m; i++){
        if(c == 0){
            recurse(c+i, i, s, m, d);
        }
        else{
            if(abs(k-i) <= d){
                recurse(c+i, i, s, m, d);
            }
        }
    }
}

int main(){
    LL s;
    int m, d;
    cin>>s>>m>>d;
    recurse(0, 0, s, m, d);
    cout<<ans;
    return 0;
}
