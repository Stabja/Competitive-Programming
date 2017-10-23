#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAXX 100005

int P[MAXX];
int A[MAXX];
int H[MAXX];
int T[MAXX];

int main(){
    int N;
    cin>>N;
    for(int i = 0; i < N; i++)
        cin>>P[i];
    for(int i = 0; i < N; i++)
        cin>>A[i];
    for(int i = 0; i < N; i++)
        cin>>H[i];
    memset(T, 10000, sizeof T);
    T[0] = A[0];
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(P[j] < P[i]){
                int val = T[j] + pow((H[i]-H[j]), 2) + A[i];
                T[i] = min(T[i], val);
            }
        }
    }
    cout<<T[N-1];
    return 0;
}
