#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int n, a[1000], b[1000], maxx = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        b[i] = a[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i] > a[j]){
                b[i] = max(b[i], a[i]+b[j]);
            }
        }
        if(b[i] > maxx){
            maxx = b[i];
        }
    }
    for(int i = 0; i < n; i++){
        cout<<b[i]<<" ";
    }
    cout<<"\n"<<maxx;
    return 0;
}
