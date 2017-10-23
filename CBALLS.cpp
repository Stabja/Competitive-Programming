#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int gcd(int m, int n){
    if(m == n)
        return m;
    else if(m > n)
        return gcd(m-n, n);
    else if(m < n)
        return gcd(m, n-m);
}

int main(){
    int T, N, a[10000], balls = 0;
    cin>>T;
    while(T--){
        cin>>N;
        for(int i = 0; i < N; i++){
            cin>>a[i];
        }
        sort(a, a+N);
        for(int i = 0; i < N-1; i++){
            int g = gcd(a[i], a[i+1]);
            if(g > 1){
                continue;
            }
            if(g == 1){
                if(a[i]%2 != 0){
                    a[i]++;
                    balls++;
                }
                if(a[i+1]%2 != 0){
                    a[i+1]++;
                    balls++;
                }
            }
        }
        cout<<balls<<"\n";
    }
    return 0;
}
