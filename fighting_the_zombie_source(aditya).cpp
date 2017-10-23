// FIGHTING_THE_ZOMBIE
#include <bits/stdc++.h>
using namespace std;
int H;
double dp[500][25];
double solve(string s) {
  int n = s.length(); bool negative = false;
  bool first = true, second = false, third = false;
  int req = 0, X = 0, Y = 0, Z = 0;
  for(int i=0;i<n;i++) {
     if(s[i] >= '0' && s[i] <= '9') {
        if(first) X = X*10 + (s[i]-'0'); else if(second) Y = Y*10 + (s[i]-'0');
        else if(third) Z = Z*10 + (s[i]-'0');
     }
     else if(s[i] == 'd') { first = false; second = true; }
     else if(s[i] == '-') { negative = true; second = false; third = true; }
     else if(s[i] == '+') { second = false; third = true; }
  }
  if(negative) req = H + Z; else req = H - Z;
  // dynamic programming bottom-up begins
  int maxi = X*Y;
  dp[0][0] = 1.0;
  for(int i=1;i<=X;i++) {
     for(int j=1;j<=maxi;j++) {
          double lp = 0.0;
          for(int k=1;k<=Y;k++) {
               if(j-k < 0) break;
               lp += dp[j-k][i-1];
          }
          dp[j][i] = lp/Y;
     }
  }
  double prob = 0.0; int lower = max(0,req);
  for(int i=lower;i<=maxi;i++) prob += dp[i][X];
  return prob;
}
int main() {
  freopen("fighting_the_zombie.txt","r",stdin);
  freopen("zombieans.txt","w",stdout);
  int t,S;
  string s;
  scanf("%d",&t);
  int cas = 1;
  while(t--) {
    scanf("%d %d",&H,&S);
    double res = 0.0;
    while(S--) {
      cin >> s;
      res = max(res,solve(s));
    }
    printf("Case #%d: %0.9lf\n",cas++,res);
  }
  return 0;
}
