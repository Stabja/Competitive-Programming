#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair

int a[1000005];
int dp[1000005];

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    dp[0] = a[0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i-1; j++){
            dp[i] += dp[j] + (i-j)*
        }
    }
    return 0;
}
