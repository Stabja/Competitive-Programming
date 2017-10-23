#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair

map<int, LL> dp;

LL recurse(int n){
    if(n == 0)
        return 0;
    if(dp[n] != 0)
        return dp[n];
    LL x = recurse(n/2)+recurse(n/3)+recurse(n/4);
    if(x > n)
        dp[n] = x;
    else
        dp[n] = n;
    return dp[n];
}

int main(){
    int n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6;
    while(scanf("%d", &n) == 1){
        cout<<recurse(n)<<"\n";
    }
    return 0;
}

