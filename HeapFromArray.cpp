#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
using namespace std;

void inserts(int arr[], int x, int sz){
    int t;
    if(arr[(sz-1)/2] < arr[sz]){
        t = arr[(sz-1)/2];
        arr[(sz-1)/2] = arr[sz];
        arr[sz] = t;
        inserts(arr, arr[(sz-1)/2], sz);
    }
}

void MaxHeapify(int A[], int i, int limit){
    int maxx = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < limit && A[i] < A[left])
        maxx = left;
    if(right < limit && A[right] > A[maxx]){
        maxx = right;
    }
    if(maxx != i){
        int c = A[i];
        A[i] = A[maxx];
        A[maxx] = c;
        MaxHeapify(A, maxx, limit);
    }
}

void CreateHeap(int A[], int N){
    for(int i = N/2-1; i >= 0; i--){
        int left = 2*i+1;
        int right = 2*i+2;
        MaxHeapify(A, i, N);
    }
}

void display(int a[], int n){
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int n, a[200], numIns, x;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    CreateHeap(a, n);
    display(a, n);
    cout<<"How many elements to insert?";
    cin>>numIns;
    for(int i = 0; i < numIns; i++){
        cin>>x;
        a[n++] = x;
        inserts(a, x, n);
        display(a, n);
    }
    /*int k = 1;
    while(n--){
        cin>>a[k-1];
        CreateHeap(a, k);
        display(a, k);
        k++;
    }*/
    return 0;
}
