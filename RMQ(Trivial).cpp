#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int arr[100], T[100][100], N;
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < N; i++){
        T[i][i] = i;
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j+i > N-1)
                continue;
            if(arr[T[j][j+i-1]] < arr[T[j+1][j+i]])
                T[j][j+i] = T[j][j+i-1];
            else
                T[j][j+i] = T[j+1][j+i];
        }
    }
    /*for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<T[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        cout<<arr[T[m][n]]<<"\n";
    }
    return 0;
}
