#include <bits/stdc++.h>
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define mod 1000000007
#define pb push_back
using namespace std;

int main() {
    fastio
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long int d,i,n,j,cnt,f,k;
    string s;
    cin>>d;
    while(d--)
    {
        f=0;
        cin>>s;
        n=s.size();
        i=0;
        j=n/2;
        cnt=0;
        if(n==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(n%2==0)
        {
            while(j<n)
            {
                if(s[i]==s[j])
                cnt++;
                j++;
                i++;
            }
            if(cnt==n/2)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            continue;
        }
        while(j<n&&s[i]!=s[j])
        {
            if(s[i]==s[j+1])
            j++;
            else if(s[i+1]==s[j])
            i++;
            else
            {
                i++;
                j++;
            }
        }
        k=j;
        i=0;
        j=n/2;
        while(i<k&&j<n)
        {

           if(s[i]==s[j])
           {
               cnt++;
               i++;
               j++;
           }
           else if(s[i]==s[j+1])
           {
               j++;

           }
           else if(s[i+1]==s[j])
           {
               i++;

           }
           else
           break;
        }
        if(cnt==n/2)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;

    }
}
