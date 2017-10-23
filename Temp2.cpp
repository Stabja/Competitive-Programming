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
#define PI 3.141592653589

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main(){
    int n, k;
    cin>>n>>k;
    if(n<k)
        cout<<-1;
    else if(k == 2 && n>2)
        cout<<-1;
    else{
        int x = n-2;
        int y = k-2;
        int each = x/y;     //4
        int ex = x%y;       //1
        int ans = each*y+each;
        ans += ex*2;
        cout<<ans;
    }
    return 0;
}
