#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int findK(int a[], int low, int high){
    int mid = (low + high) / 2;
    if(a[mid] > a[mid-1] && a[mid] > a[mid+1]){
        return a[mid];
    }
    else if(a[mid-1] < a[mid] && a[mid] < a[mid+1]){
        return findK(a, mid+1, high);
    }
    else if(a[mid-1] > mid && a[mid] > a[mid+1]){
        return findK(a, low, mid-1);
    }
}

int main(){
    int n, a[100];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int x = findK(a, 0, n-1);
    cout<<x;
    return 0;
}
