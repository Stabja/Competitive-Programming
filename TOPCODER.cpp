#include<bits/stdc++.h>
using namespace std;

int a1,a2;
int dp[320][320];
int vis[320][320];

int solve(int x,int y)
{
    if(x>y)
        swap(x,y);
    if(x<=0)
        return 0;
    if(vis[x][y])              //If already calculated the then just return it
        return dp[x][y];
    vis[x][y]=1;
    dp[x][y] = max(solve(x-2,y+1),solve(x+1,y-2))+1;  //Else calculate it
    return dp[x][y];
}

int main()
{
    cin>>a1>>a2;
    if(a1==1&&a2==1)return puts("0"),0;
    cout<<solve(a1,a2)<<endl;
}
