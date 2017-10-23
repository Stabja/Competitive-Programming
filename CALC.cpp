#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, B;
        cin>>N>>B;
        int x = N/2;
        int y = N/2;
        if(B == 1){
            int ans = x*y;
            cout<<ans<<"\n";
        }
        else{
            int k = y%B;
            int l = B-k;
            int m = x-l;
            int n = x+l;
            int ans = m*(n/B);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
