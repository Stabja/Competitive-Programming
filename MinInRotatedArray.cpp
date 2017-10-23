#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<int> series;

int FindMin(int L, int R){
    int mid = (L+R)/2;
    if(L > R)
        return -1;
    if(series[mid] < series[mid-1] && series[mid] < series[mid+1])
        return mid;
    else if(series[mid] > series[L])
        return FindMin(mid+1, R);
    else if(series[mid] < series[L]){
        return FindMin(L, mid-1);
    }
}

int main(){
    int arr[1000];
    int T;
    cin>>T;
    while(T--){
        int N, R;
        cin>>N>>R;
        for(int i = 1; i <= N-R; i++){
            series.push_back(R+i);
        }
        for(int i = 1; i <= R; i++){
            series.push_back(i);
        }
        for(int i = 0; i < series.size(); i++){
            cout<<series[i]<<" ";
        }
        cout<<"\n";
        cout<<FindMin(0, N-1)<<"\n";
        series.clear();
    }
    return 0;
}
