#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int cnt = 0;
        for(int i = 0; i < str.length()-1; i++){
            if(str[i+1] != str[i]){
                cnt++;
            }
        }
        int ans = cnt/2;
        if(str[str.length()-1] == str[0]){
            cout<<ans<<"\n";
        }
        else{
            cout<<ans+1<<"\n";
        }
    }
    return 0;
}
