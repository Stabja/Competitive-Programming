#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,n) for(int i=a;i<n;i++)
#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back

vector<int> v;

int main()
{
    LL n,x;
    cin>>n>>x;
    int a;
    for(int i = 0; i < n; i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    vector<int>::iterator it1, it2, it3;
    LL ans = 0;
    for(it1 = v.begin(); it1 != v.end(); ++it1)
    {
        int temp = x ^ *it1;
        it2 = lower_bound(it1+1, v.end(), temp);
        it3 = upper_bound(it1+1, v.end(), temp);
        if(it2 == v.end()){
            continue;
        }
        ans += it3 - it2;
    }
    cout<<ans;
    return 0;
}

