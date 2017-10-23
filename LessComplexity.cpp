#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <iostream>
using namespace std;

#define MAX 100001

int arr[MAX];
int dp[MAX];
bool flag[MAX];


int main()
{
    int m,n,a;
    scanf("%d %d",&n,&m);

    for(int i = 0; i < n ; i++)
        scanf("%d", &arr[i]);

    for(int i= n-1; i >= 0; i--)
    {
        if(!flag[arr[i]])
        {
            dp[i]++;
            flag[arr[i]] = true;
        }
        dp[i] += dp[i+1];
    }

    for(int i = 0; i < m; i++)
    {
        scanf("%d", &a);
        printf("%d\n",dp[a-1]);
    }

    return 0;
}
