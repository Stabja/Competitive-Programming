#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,n) for(int i=a;i<n;i++)
#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sd(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%ld",&n)
#define sll(n) scanf("%lld",&n)
#define sf(n) scanf("%f",&n)
#define ss(n) scanf("%s",n)
#define pd(a) printf("%d\n",a)
#define pc(a) printf("%c",a)
#define pl(a) printf("%ld\n",a)
#define pll(a) printf("%lld\n",a)
#define pf(a) printf("%f\n",a)
#define ps(a) printf("%s\n",a)
#define fastio ios_base::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
#define fopen freopen("myfile.txt", "w", stdout);
#define fcl fclose(stdout);

int main(){
    while(1){
        char str[5010];
        ss(str);
        if(str[0]=='0')
            break;
        LL dp[5010];
        LL len = strlen(str);
        memset(dp,0,5010);
        dp[0] = 1;
        LL x;
        for(LL i = 1; i < len; i++){
            x = (str[i-1]-'0')*10+(str[i]-'0');
            if(str[i]-'0'){
                dp[i]=dp[i-1];
            }
            if(x >= 10 && x <= 26){
                if(i-2 < 0){
                    dp[i] += dp[0];
                }
                else{
                    dp[i] += dp[i-2];
                }
            }
        }
        pll(dp[len-1]);
    }
    return 0;
}

