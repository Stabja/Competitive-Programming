#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair

int dp[100005][3];

int main(){
    int k = 1;
    while(1){
        int n;
        cin>>n;
        if(n == 0)
            break;
        for(int i = 0; i < n; i++){
            cin>>dp[i][0]>>dp[i][1]>>dp[i][2];
        }

        dp[1][0] += dp[0][1];
        dp[0][2] += dp[0][1];
        dp[1][1] += min(dp[1][0], min(dp[0][1], dp[0][2]));
        dp[1][2] += min(dp[1][1], min(dp[0][1], dp[0][2]));

        for(int i = 2; i < n; i++){
            dp[i][0] += min(dp[i-1][0], dp[i-1][1]);
            dp[i][1] += min(dp[i][0], min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])));
            dp[i][2] += min(dp[i][1], min(dp[i-1][1], dp[i-1][2]));
        }
        cout<<k<<". "<<dp[n-1][1]<<"\n";
        k++;
    }
    return 0;
}
