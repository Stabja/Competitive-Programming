#include<bits/stdc++.h>
using namespace std;

char symbol[100];

void result(int arr[], int k, int N, int sum){
    if(k == N){          //If all the numbers are covered
        if(sum == arr[N]){
            for(int i = 0; i < N-1; i++){
                cout<<symbol[i]<<" ";
            }
            return;
        }
    }
    else{
        sum += arr[k];
        symbol[k] = '+';
        result(arr, k+1, N, sum);
        sum -= 2*arr[k];
        symbol[k] = '-';
        result(arr, k+1, N, sum);
    }
}

int main(){
    int n, a[100];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cin>>a[n];
    result(a, 0, n, 0);

    return 0;
}
