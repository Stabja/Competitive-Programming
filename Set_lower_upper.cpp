#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,n) for(int i=a;i<n;i++)
#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back

set<int> ss;
int arr[100005];

int main(){
    int arr[100];
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        ss.insert(arr[i]);
    }
    for(set<int>::iterator it = ss.begin(); it != ss.end(); ++it){
        cout<<*it<<" ";
    }
    set<int>::iterator it1, it2;
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        it1 = lower_bound(ss.begin(), ss.end(), x);
        it2 = upper_bound(ss.begin(), ss.end(), x);
        cout<<(*it1)<<" "<<(*it2)<<"\n";
    }
    return 0;
}
