#include<bits/stdc++.h>
using namespace std;

stack<string> parity;

int main(){
    int n, p;
    cin>>n>>p;
    int k = n;
    long double fac = 0.5;
    long double numApp = 0.5;
    while(k--){
        string str;
        cin>>str;
        parity.push(str);
    }
    parity.pop();
    while(!parity.empty()){
        string x = parity.top();
        parity.pop();
        if(x.compare("halfplus") == 0){
            fac = fac*2 + 0.5;
            numApp += fac;
        }else{
            fac = fac*2;
            numApp += fac;
        }
    }
    long long int ans = 1LL*p*numApp;
    cout<<ans;
    return 0;
}
