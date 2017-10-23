#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair

pair<int, int> mat[1000];
int T[100][100];

void debug(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<T[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>mat[i].first>>mat[i].second;
    }
    for(int i = 0; i < n; i++){
        T[i][i] = 0;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n-i; j++){
            T[j][j+i] = MAXX;
            for(int k = j; k < j+i; k++){
                T[j][j+i] = min(T[j][j+i], T[j][k] + T[k+1][j+i] + mat[j].first*mat[k].second*mat[j+i].second);
            }
        }
    }
    //debug(n);
    cout<<T[0][n-1];
    return 0;
}
