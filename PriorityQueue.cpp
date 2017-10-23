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

//priority_queue<int, vector<int>, std::greater<int> > pq;
priority_queue<int> pq;

int main(){
    int n;
    cin>>n;
    int k;
    for(int i = 0; i < n; i++){
        cin>>k;
        pq.push(k);
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}
