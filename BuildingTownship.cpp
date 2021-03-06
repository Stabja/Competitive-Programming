#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MaxK = 201;
int br = 0;
int dp[MaxK][MaxK], next1[MaxK];
int time1[MaxK], cost[MaxK], prev1[MaxK], k, n, ce, t, tt;
int preffix[MaxK][MaxK], sum;
bool used[MaxK];
int x[MaxK][MaxK];
int cnt[MaxK], pr, dr, now[MaxK][MaxK];

void prepare(int n, int m)
{
  int sum = 0; time1[0] = 0;
  for (int i=0; i<=cnt[n]; i++)
  {
    sum += time1[x[n][i]];
    int sum1 = 0;

    for (int j=0; j<=cnt[m]; j++)
    {
      sum1 += time1[x[m][j]];
      preffix[i][j] = sum + sum1;
    }
  }

  memset(dp, 0, sizeof(dp));
  sum = 0;
  int tt = 0;

  for (int i=1; i<=cnt[n]; i++)
  {
    tt = preffix[i][0];
    dp[i][0] = dp[i-1][0] + tt * cost[x[n][i]];
  }

  sum = 0;
  tt = 0;

  for (int j=1; j<=cnt[m]; j++)
  {
    tt = preffix[0][j];
    dp[0][j] = dp[0][j-1] + tt * cost[x[m][j]];
  }
 //cout << cnt[n] << " " << cnt[m] << endl;
/*
  for (int i=0; i<=cnt[n]; i++)
    for (int j=0; j<=cnt[m]; j++)
  {
   if (j!=cnt[m]) cout << dp[i][j] <<  " ";
   else cout << dp[i][j] << endl;
  }
*/
}

void update(int a, int b, int n, int m)
{
  cnt[1] = sum;
  while (sum > 0)
  {
    if (((n>0) && (now[n][m] == 1)) || (m == 0))
    {
      x[1][sum] = x[a][n];
      n--;
    }
    else
    {
      x[1][sum] = x[b][m];
      m--;
    }
   sum --;
  }
}

int rek(int a, int b)
{
   if (dp[a][b] > 0) return dp[a][b];

   int sum1 = rek(a-1, b) + preffix[a][b] * cost[x[pr][a]];
   int sum2 = rek(a, b-1) + preffix[a][b] * cost[x[dr][b]];

   if (sum1 < sum2)
   {
     dp[a][b] = sum1;
     now[a][b] = 1;
   }
   else
   {
     dp[a][b] = sum2;
     now[a][b] = 2;
   }

  return dp[a][b];
}

int main()
{
 scanf("%d", &t);      //No of Test cases

 while (t--)
 {
   ce++;
   br = 0;
   scanf("%d", &k);    //No of groups
   memset(x, 0, sizeof(x));
   memset(next1, 0, sizeof(next1));
  memset(prev1, 0, sizeof(prev1));
  memset(cnt, 0, sizeof(cnt));
  memset(used, false, sizeof(used));
  memset(preffix, 0 ,sizeof(preffix));
  int i;

  for (i=1; i<=k; i++)
    scanf("%d", &time1[i]);  //No of days required to finish the subparts
  for (i=1; i<=k; i++)
    scanf("%d", &cost[i]);   //Hiring cost per day
  for (i=1; i<=k; i++)
  {
    next1[i] = i;
    prev1[i] = i;
  }

  scanf("%d", &n);           //No of dependencies

  for (i=1; i<=n; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);    //Dependencies
    next1[b] = a;
    prev1[a] = b;
  }

  for (i=1; i<=k; i++)
  {
     if (!used[i])
     {
        br ++;
        int a = next1[i];
        while (a != next1[a]){
            a = next1[a];
        }

        while (1 == 1)
        {
           x[br][++cnt[br]] = a;
           used[a] = true;
           if(a == prev1[a]) break;
           a = prev1[a];
        }
     }
  }

  int k1, k2;

  if (br == 1)
  {
    tt = 0;
    sum = 0;
    for (i=1; i<=k; i++)
    {
      tt += time1[x[1][i]];
      sum += (tt * cost[x[1][i]]);
    }
    cout << "Case "<< ce << ": " << sum << endl;
    continue;
  }

  for (i=2; i<=br; i++)
  {
    pr = 1; dr = i;
    k1 = cnt[pr]; k2 = cnt[dr];
    prepare(pr, dr);
    rek(cnt[pr], cnt[dr]);
    sum = cnt[pr] + cnt[dr];
    update(pr, dr, cnt[pr],cnt[dr]);
  }
  cout << "Case " << ce << ": " << dp[k1][k2] << endl;
  }
}
