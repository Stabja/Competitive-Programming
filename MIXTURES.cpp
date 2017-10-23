#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair

int arr[100005];
int T[101][101];
int A[101][101];

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        for(int i = 0; i < n; i++){
            T[i][i] = 0;
            A[i][i] = arr[i];
        }
        for(int k = 1; k < n; k++){
            for(int i = 0; i < n-k; i++){
                int j = i+k;
                if(j >= n) continue;
                LL x = T[i][j-1] + 1LL*A[i][j-1]*arr[j];    //a*b
                LL y = T[i+1][j] + 1LL*A[i+1][j]*arr[i];
                if(x < y){
                    T[i][j] = x;
                    A[i][j] = (A[i][j-1] + arr[j])%100;     //(a+b)%100
                }
                else{
                    T[i][j] = y;
                    A[i][j] = (A[i+1][j] + arr[i])%100;     //(a+b)%100
                }
            }
        }
        cout<<T[0][n-1]<<"\n";
        memset(T, 0, sizeof T);
        memset(A, 0, sizeof A);
    }
    return 0;
}
