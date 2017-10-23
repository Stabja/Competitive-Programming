#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

LL freq[26];
LL dp[100005];

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        LL n = str.length();
        freq[str[0]-'A']++;
        dp[0] = 2;
        for(int i = 1; i < n; i++){
            int idx = str[i]-'A';
            LL temp = (dp[i-1]-freq[idx]+MAXX)%MAXX;
            dp[i] = (dp[i-1]+temp)%MAXX;
            freq[idx] = (freq[idx]+temp)%MAXX;
        }
        cout<<dp[n-1]<<"\n";
        memset(freq, 0, sizeof freq);
        memset(dp, 0, sizeof dp);
    }
}
