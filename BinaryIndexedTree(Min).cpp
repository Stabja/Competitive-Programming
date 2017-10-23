#include<iostream>
using namespace std;

int BITree[100001];

int getSum(int index){
    index++;
    int sum = 0;
    while(index > 0){
        sum += BITree[index];
        index = index - (index & (-index)); //Getting the parent by flipping the rightmost set bit
    }
    return sum;
}

int updateBITree(int n, int index, int val){
    index++;
    while(index <= n){
       BITree[index] += val;
       index = index + (index & (-index));        //Going to the next element
    }
}

void constructBITree(int arr[], int n){
    for(int i = 0; i <= n; i++){
        BITree[i] = 0;
    }
    for(int i = 0; i < n; i++){
        updateBITree(n, i, arr[i]);
    }
}

int main(){
    int arr[] = {34, 27, 14, 6, 8, 19, 4, 16, 24, 36, 23, 11, 9, 13, 5, 3, 41, 17, 27, 15};
    /////////////00, 01, 02, 3, 4, 05, 6, 07, 08, 09, 10, 11, 12,13,14,15, 16, 17, 18, 19
    int n = sizeof(arr)/sizeof(arr[0]);
    constructBITree(arr, n);
    for(int i = 0; i <= n; i++){
        cout<<BITree[i]<<" ";
    }
    cout<<"\n";
    int Q, L, R;
    cin>>Q;
    while(Q--){
        cin>>L>>R;
        cout<<getSum(R) - getSum(L-1)<<"\n";
    }
    /*arr[3] += 6;
    updateBITree(n, 3, 6);
    cout<<"\nSum after updating element 3 is "<<getSum(n, 5)<<"\n";*/
    return 0;
}
