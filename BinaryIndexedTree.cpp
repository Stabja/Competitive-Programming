#include<iostream>
using namespace std;

int getSum(int BITree[], int n, int index){
    index++;
    int sum = 0;
    while(index > 0){
        sum += BITree[index];
        index -= index & (-index);   //Getting the parent by flipping the rightmost set bit
    }
    return sum;
}

int updateBITree(int *BITree, int n, int index, int val){
    index++;
    while(index <= n){
       BITree[index] += val;
       index += index & (-index);       //Going to the next element
    }
}

int *constructBITree(int arr[], int n){
    int *BITree = new int[n+1];
    for(int i = 0; i <= n; i++){
        BITree[i] = 0;
    }
    for(int i = 0; i < n; i++){
        updateBITree(BITree, n, i, arr[i]);
    }
    return BITree;
}

int main(){
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    int *BITree = constructBITree(freq, n);
    for(int i = 0; i <= n; i++){
        cout<<BITree[i]<<" ";
    }
    cout<<"\nSum of elements from 0 to 5 is "<<getSum(BITree, n, 5);
    cout<<"\nSum of elements from 5 to 8 is "<<getSum(BITree, n, 8) - getSum(BITree, n, 4);
    freq[3] += 6;
    updateBITree(BITree, n, 3, 6);
    cout<<"\nSum after updating element 3 is "<<getSum(BITree, n, 5)<<"\n";
    for(int i = 0; i <= n; i++){
        cout<<BITree[i]<<" ";
    }
    //To get sum from x to y, getSum(y) - getSum(x-1)
    return 0;
}
