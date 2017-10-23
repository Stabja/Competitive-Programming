#include<bits/stdc++.h>
using namespace std;

long long int dp[100005];

long long int fibo(long long int x){
    if(x == 1)
        return 1;
    if(x == 0)
        return 1;
    if(dp[x])        //If already calculated, just return it
        return dp[x];
    dp[x] = fibo(x-1) + fibo(x-2);  //Else calculate it
    return dp[x];
}

int main(){
    dp[0] = 1;
    dp[1] = 1;
    cout<<fibo(500)<<"\n";
    for(int i = 0; i <= 10; i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}
