#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    pair<int, int> a[100];
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    a[0].first = -1;
    sort(a+1, a+1+n);
    cout<<"\n";
    for(int i = 0; i <= n; i ++){
        cout<<a[i].first<<" ";
    }
    cout<<"\n";
    for(int i = 0; i <= n; i++){
        cout<<a[i].second<<" ";
    }
    return 0;
}
