#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000009
#define LL long long int
#define mp make_pair
#define pb push_back

int main(){
    int t;
    cin>>t;
    while(t--){
        string s,str="";
        cin>>s;
        int ans=1,cnt=1;
        for(int i=0;i<s.size();++i){
            if(s[i]!='=')
                str+=s[i];
        }
        if(str.size()<=1){
            cout<<str.size()+1<<endl;
            continue;
        }
        for(int i=1;i<str.size();++i){
            if(str[i-1]==str[i]){
                cnt++;
            }
            else{
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        ans=max(ans,cnt)+1;
        cout<<ans<<endl;
    }
    return 0;
}
