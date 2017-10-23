#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair
#define LD long double
#define pi 3.14159265358979323

LL power(LL x, LL y, LL p){                //Inverse using modular exponentiation
    LL res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;

        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, z;
        cin>>x>>y>>z;
        cout<<power(x, y, z)<<"\n";
    }
    return 0;
}
