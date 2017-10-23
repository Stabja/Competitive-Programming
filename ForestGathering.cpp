#include <bits/stdc++.h>
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define mod 1000000007
#define pb push_back
#define mp make_pair
using namespace std;

vector < pair< int, pair<int , int> > > p(111111);
pair<int, int> prefix[111111];

int main(){
    //fastio
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long n,w,l,i,lo,hi,mid,f=0,sum=0;
    cin>>n>>w>>l;
    for(i=0;i<n;i++)
    {
        cin>>p[i].se.fi>>p[i].se.se;
        p[i].fi=ceil((double)(l-p[i].se.fi)/(double)p[i].se.se);
        if(p[i].fi<0)
        p[i].fi=0;
    }
    sort(p.begin(),p.begin()+n);
    prefix[0].fi=p[0].se.fi;
    prefix[0].se=p[0].se.se;
    for(i=1;i<n;i++)
    {
        prefix[i].fi=p[i].se.fi+prefix[i-1].fi;
        prefix[i].se=p[i].se.se+prefix[i-1].se;
    }
    for(i=0;i<n;i++)
    {
        sum=prefix[i].fi+(prefix[i].se*p[i].fi);
        if(sum==w)
        {
            cout<<p[i].fi;
            return 0;
        }
        if(sum>w)
        {
            f=1;
            break;
        }
    }
    if(f!=1)
    {
        w-=prefix[n-1].fi;
        w=ceil((double)w/(double)prefix[n-1].se);
        cout<<w;
        return 0;
    }
    lo=p[i-1].fi+1;
    hi=p[i].fi-1;
    sum=prefix[i-1].fi+(prefix[i-1].se*hi);
    if(sum<w)
    {
        cout<<p[i].fi;
        return 0;
    }
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        sum=prefix[i-1].fi+(prefix[i-1].se*mid);

        if(sum>w)
            hi=mid-1;
        else if(sum<w)
            lo=mid+1;
        else
            break;
    }
    sum=prefix[i-1].fi+(prefix[i-1].se*(mid-1));
    if(sum>=w)
    cout<<mid-1;
    else if(sum+prefix[i-1].se>=w)
    cout<<mid;
    else
    cout<<mid+1;

}
