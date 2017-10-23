#include<bits/stdc++.h>
using namespace std;

int dp[350][350];

int calc(int x, int y){
    if(x <= 0 || y <= 0)
        return 0;
    if(dp[x][y])
        return dp[x][y];
    cout<<x-2<<" "<<y+1<<"    "<<x+1<<y-2<<"\n";
    dp[x][y] = max(calc(x-2, y+1), calc(x+1, y-2)) + 1;
    return dp[x][y];
}

int main(){
    int a, b;
    cin>>a>>b;
    if(a == 1 && b == 1)
        cout<<0;
    else
        cout<<calc(a, b);
    return 0;
}
