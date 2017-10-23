#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

long long int A[100005];
long long int B[100005];
long long int C[100005];

int main(){
    int T;
    cin>>T;
    while(T--){
        int N, K;
        cin>>N>>K;
        for(int i = 0; i < N; i++)
            cin>>A[i];
        for(int i = 0; i < N; i++)
            cin>>B[i];
        int maxx = 0;
        int index = 0;
        int flag = 0;
        for(int i = 0; i < N; i++){
            C[i] = 1LL*A[i]*B[i];
            if(C[i] > 0 && abs(B[i]) > maxx){
                maxx = abs(B[i]);
                index = i;
                flag = 1;
            }
        }
        for(int i = 0; i < N; i++){

        }
        C[index] += abs(B[index]*K);
        long long int sum = 0;
        for(int i = 0; i < N; i++){
            sum += C[i];
        }
        cout<<sum<<"\n";
    }
    return 0;
}
