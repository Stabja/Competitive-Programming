#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,n) for(int i=a;i<n;i++)
#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back

set<int> s;

int main(){
    int n;
    cin>>n;
    int k;
    for(int i = 0; i < n; i++){
        cin>>k;
        s.insert(k);
    }
    int cur = 1;
    while(1){
        int x = *s.rbegin();
        int cur = x;
        cur = cur /2;
        while(s.find(cur) != s.end()){
            cur /= 2;
        }
        if(cur == 0)
            break;
        s.erase(x);
        s.insert(cur);
    }
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it){
        cout<<*it<<" ";
    }
    return 0;
}
