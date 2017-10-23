#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,n) for(int i=a;i<n;i++)
#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back

int dp[100005];
int a[100005];

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        if(a[i] >= a[i-1])
            dp[i] = dp[i-1] + 1;
        else
            dp[i] = 1;
    }
    for(int i = 0; i < n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
    cout<<*max_element(dp, dp+n)<<"\n";
    return 0;
}
