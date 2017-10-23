#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define MAXX 1000000000
#define LL long long int
#define pb push_back
#define mp make_pair

bool prime[100005];

LL Sieve(int r){
    LL sum = 0;
    memset(prime, true, sizeof(prime));
    bool done = false;
    for(int p=3; p<=r; p++){
        if(!done){
            done = true;
            sum += r;
        }
        if(prime[p] == true){
            sum += p;
            for(int i=p*2; i<=r; i += p){
                if(prime[i] == true){
                    prime[i] = false;
                }
                sum += p;
            }
        }
        else{
            if(p%2 == 0){
                sum += p;
            }
        }
    }
    return sum;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int l, r;
        cin>>l>>r;
        LL ans = Sieve(r) - Sieve(l-1);
        cout<<ans<<"\n";
    }
    return 0;
}
