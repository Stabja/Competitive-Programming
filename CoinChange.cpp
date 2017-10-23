#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, v[200], P, T[200][200];
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>v[i];
    }
    cin>>P;
    T[0][0] = 0;
    for(int i = 1; i <= P; i++){
        T[0][i] = 10000;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= P; j++){
            if(j >= v[i]){
                T[i][j] = min(T[i-1][j], T[i][j-v[i]] + 1);
            }
            else{
                T[i][j] = T[i-1][j];
            }
            cout<<T[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<T[n-1][P];
    return 0;
}
