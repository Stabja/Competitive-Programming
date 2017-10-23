#include<bits/stdc++.h>
using namespace std;

int arr[100];

void FindPath(int T[][100], int m, int n, int i, int j, int x){
    if(i == m){
        for(int i = 0; arr[i] != 0; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    if(j == n){
        for(int i = 0; arr[i] != 0; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    arr[x++] = T[i][j];
    FindPath(T, m, n, i+1, j, x);
    FindPath(T, m, n, i, j+1, x);
}

int main(){
    int m, n, T[100][100];
    cin>>m>>n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>T[i][j];
        }
    }
    FindPath(T, m, n, 0, 0, 0);
    return 0;
}
