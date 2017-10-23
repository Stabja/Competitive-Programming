#include<bits/stdc++.h>
using namespace std;

bool fillUtil(int arr[], int curr, int n){
    if(curr == 0){
        return true;
    }
    for(int i = 0; i < 2*n-curr-1; i++){
        if(arr[i] == 0 && arr[i+curr+1] == 0){
            arr[i] = arr[i+curr+1] = curr;
            if(fillUtil(arr, curr-1, n)){
                return true;
            }
            arr[i] = arr[i+curr+1] = 0;
        }
    }
    return false;
}

int main(){
    int T, n, a[10000];
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 0; i < 2*n; i++){
            a[i] = 0;
        }
        bool isTru = fillUtil(a, n, n);
        if(isTru){
            for(int i = 0; i < 2*n; i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
        else
            cout<<0<<"\n";
    }
    return 0;
}
