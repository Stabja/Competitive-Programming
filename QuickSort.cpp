#include<bits/stdc++.h>
using namespace std;

int arr[1000];

void QuickSort(int A[], int l, int r){
    if(l >= r)
        return;
    int p = A[r];
    int j = r;
    int i = l;
    while(1){
        while(A[j] > p)
            j--;
        while(A[i] < p)
            i++;
        if(i < j){
            int c = A[i];
            A[i] = A[j];
            A[j] = c;
            j--;
            i++;
        }
        else
            break;
    }
    QuickSort(A, l, j);
    QuickSort(A, j+1, r);
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    QuickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
