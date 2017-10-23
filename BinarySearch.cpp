#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int ar[], int low, int high, int x){
    int mid = (low + high)/2;
    if(low > high){
        return -1;
    }
    if(x == ar[mid]){
        return mid;
    }
    else if(x > ar[mid]){
        return BinarySearch(ar, mid+1, high, x);
    }
    else if(x < ar[mid]){
        return BinarySearch(ar, low, mid-1, x);
    }
}

int main() {
    int A[1001], N, V;
    cin>>V>>N;
    for(int i = 0; i < N; i++){
        cin>>A[i];
    }
    cout<<BinarySearch(A, 0, N-1, V);
    return 0;
}
