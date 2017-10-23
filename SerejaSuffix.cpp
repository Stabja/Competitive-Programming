#include<bits/stdc++.h>
using namespace std;

int main(){
    long n, m, a[100001], ans[100001], x;
    bool flag[100001];
    cin>>n>>m;
    for(long i = 0; i < n; i++){
        cin>>a[i];
    }
    for(long i = n-1; i >= 0; i--){
        if(!flag[a[i]]){
            flag[a[i]] = true;
            ans[i] = ans[i+1] + 1;
        }
        else{
            ans[i] = ans[i+1];
        }
    }
    while(m--){
        cin>>x;
        cout<<ans[x-1]<<"\n";
    }
    return 0;
}
