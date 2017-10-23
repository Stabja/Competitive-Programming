#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,n) for(int i=a;i<n;i++)
#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back

int P[25], Q[25], R[25], S[25];

bool isSubsetSum(int sett[], int n, int sum){
    bool subset[sum+1][n+1];
    for(int i = 0; i <= n; i++){
        subset[0][i] = true;
    }
    for(int i = 1; i <= sum; i++){
        subset[i][0] = false;
    }
    for(int i = 1; i <= sum; i++){
        for(int j = 1; j <= n; j++){
            subset[i][j] = subset[i][j-1];
        if(i >= sett[j-1])
            subset[i][j] = subset[i][j] || subset[i - sett[j-1]][j-1];
        }
    }
    return subset[sum][n];
}

int main(){
    int a, b, c, d;
    int n;
    cin>>a>>b>>c>>d>>n;
    for(int i = 0; i < n; i++){
        cin>>P[i]>>Q[i]>>R[i]>>S[i];
    }
    bool pp = isSubsetSum(P, n, a);
    bool qq = isSubsetSum(Q, n, b);
    bool rr = isSubsetSum(R, n, c);
    bool ss = isSubsetSum(S, n, d);
    if(pp == 1 && qq == 1 && rr == 1 && ss == 1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
