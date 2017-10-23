#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,n) for(int i=a;i<n;i++)
#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back
#define MAXX 1000001

bool compare(int a, int b){
    if(a < b)
        return true;
    else
        return false;
}

int main(){
    int arr[] = {10, 20, 30, 40, 10, 20, 30, 40, 20, 20, 30, 40, 40, 40, 40, 40, 40};
    vector<int> v(arr, arr+17);
    sort(v.begin(), v.end(), compare);
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<"\n";
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        vector<int>::iterator it1, it2;
        it1 = lower_bound(v.begin(), v.end(), x);
        it2 = upper_bound(v.begin(), v.end(), x);
        int val = count(v.begin(), v.end(), x);
        cout<<val<<"\n";
        cout<<(it1 - v.begin())<<" "<<(it2 - v.begin())<<"\n";
    }
    return 0;
}
