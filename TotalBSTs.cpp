#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int arr[10000];

int main(){
    int N;
    cin>>N;
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i < N; i++){
        for(int j = 0; j < i; j++){
            arr[i] += arr[j]*arr[i-j-1];
        }
    }
    for(int i = 0; i < N; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
