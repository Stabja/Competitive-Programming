#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, wt[200], val[200], lim, mat[200][200];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>wt[i];
    }
    for(int i = 0; i < n; i++){
        cin>>val[i];
    }
    cin>>lim;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= lim; j++){
            if(wt[i] > j){
                mat[i][j] = mat[i-1][j];
            }
            else{
                mat[i][j] = max(val[i] + mat[i-1][j-wt[i]], mat[i-1][j]);
            }
        }
    }
    cout<<mat[n-1][lim];
    return 0;
}
