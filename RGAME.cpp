#include<bits/stdc++.h>
#include<cmath>
using namespace std;

const long long int BIG = 1000000007;
list<long long int> state;
long long int arr[100000];
long long int a[100000];

long long int compute(int k, int i, long long int N){
    long long int sum = 0;
    state.push_front(a[i+1]);
    list<long long int>::iterator it = state.begin();
    arr[2*k+1] = (*it)*(*++it);
    sum += (pow(2, N-i-1)*arr[2*k+1]);
    if(i<N-1){
        sum += compute(2*k+1, i+1, N);
    }
    if(sum>BIG){
        sum = sum%BIG;
    }
    state.pop_front();

    state.push_back(a[i+1]);
    list<long long int>::iterator it2 = state.end();
    --it2;
    arr[2*k+2] = (*it2)*(*--it2);
    sum += pow(2, N-i-1)*arr[2*k+2];
    if(i<N-1){
        sum += compute(2*k+2, i+1, N);
    }
    if(sum>BIG){
        sum = sum%BIG;
    }
    state.pop_back();
    return sum;
}

int main(){
    long long int T, N, sum = 0;
    cin>>T;
    while(T--){
        sum = 0;
        cin>>N;
        for(int i = 0; i <= N; i++){
            cin>>a[i];
        }
        if(N == 0){
            cout<<a[0]<<"\n";
            continue;
        }
        state.push_back(a[0]);
        arr[0] = a[0];
        sum = compute(0, 0, N);
        /*for(int i = 0; i < pow(2,N+1)-1; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";*/
        cout<<sum%BIG<<"\n";
    }
    return 0;
}
