#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    long long int T, n1, n2, m;
    cin>>T;
    while(T--){
        cin>>n1>>n2>>m;
        long long int x = m*(m+1)/2;
        x = min(x, min(n1, n2));
        n1-=x;
        n2-=x;
        cout<<n1+n2<<"\n";
    }
    return 0;
}
