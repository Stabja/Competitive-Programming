#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    int x = max(a, b);
    int y = min(a, b);
    int ans = 0;
    int m;
    int n = x;
    while(n != 0){
        ans = y;
        m = x/y;
        n = x%y;
        x = y;
        y = n;
    }
    return ans;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N, M;
        cin>>N>>M;
        int cakes = N/gcd(N,M);
        if(cakes == N)
            cout<<"YES\n";
        else
            cout<<"NO "<<cakes<<"\n";
    }
    return 0;
}
