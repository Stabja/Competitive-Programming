#include<bits/stdc++.h>
using namespace std;

int arr[1000], L;
int b[1000];

void backtrack(int N, int k){
    if(N == 0){
        for(int i = 0; i < L ; i++){
            cout<<arr[i];
        }
        cout<<"\n";
        return;
    }
    arr[k] = 0;
    backtrack(N-1, k+1);
    arr[k] = 1;
    backtrack(N-1, k+1);
}

void AllStrings(int N){
    if(N == 0){
        for(int i = 0; i < L; i++){
            cout<<arr[i];
        }
        cout<<"\n";
        return;
    }
    for(int j = 0; j < L; j++){
        b[N-1] = arr[j];
        AllStrings(N-1);
    }
}

int main(){
    int N;
    cin>>N;
    L = N;
    //backtrack(N, 0);
    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }
    AllStrings(N);
    return 0;
}
