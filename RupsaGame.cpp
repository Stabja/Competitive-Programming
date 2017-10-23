#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int T, N, a[10000];
    cin>>T;
    while(T--){
        cin>>N;
        for(int i = 0; i <= N; i++){
            cin>>a[i];
        }
        int ans = 0;
        int en = N+1;
        for(int i = 0; i < en; i++){
            int temp = a[i]*pow(2, i-1);
            for(int j = i+1; j < en; j++){
                ans += a[j]*pow(2, en-j)*temp;
            }
        }
        cout<<2*ans;
    }
    return 0;
}
