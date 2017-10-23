#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;

int T[100][100];
int arr[100];

void generateMat(int N){
    int m = N;
    int n = floor(log2(N));
    T[N-1][0] = N-1;
    for(int i = N-2; i >= 0; i--){
        T[i][0] = i;
        for(int j = 1; j <= n; j++){
            if(pow(2, j) > N-i )
                continue;
            if(arr[i] <= arr[T[i+1][j-1]]){
                T[i][j] = i;
            }
            else{
                T[i][j] = T[i+1][j-1];
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int N = floor(log2(n));
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= N; j++){
            T[i][j] = 0;
        }
    }
    generateMat(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= N; j++){
            cout<<T[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
