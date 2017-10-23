#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back

int d[2000];
int v[2000];
int ans[2000];

int main(){
    int n, x;
    cin>>n>>x;
    int c = 0;
    for(int i = 0; i < n ;i++){
        cin>>c;
        d[i] = abs(c-x);
    }
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    for(int i = 0; i < n; i++){
        ans[i] = d[i]/v[i];
    }
    int sm = INT_MAX;
    int index = 0;
    for(int i = 0; i < n; i++){
        //sm = min(sm, ans[i]);
        if(ans[i] < sm){
            sm = ans[i];
            index = i;
        }
    }
    int cnt = 0;
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(ans[i] == sm){
            cnt++;
        }
        if(cnt >= 2){
            flag = 1;
            break;
        }
    }
    if(flag){
        cout<<-1;
    }else{
        cout<<index<<"\n";
    }
    return 0;
}
