#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int arr[100000];
int minTree[400000];
int maxTree[10000];

int queryTreeMin(int ql, int qh, int l, int h, int pos){
    if(l <= ql && h >= qh){
        return minTree[pos];
    }
    if(qh < l || ql > h ){
        return 0;
    }
    int mid = (ql+qh)/2;
    return min(queryTreeMin(ql, mid, l, h, 2*pos+1), queryTreeMin(mid+1, qh, l, h, 2*pos+2));
}

int queryTreeMax(int ql, int qh, int l, int h, int pos){
    if(l <= ql && h >= qh){
        return maxTree[pos];
    }
    if(qh < l || ql > h ){
        return 0;
    }
    int mid = (ql+qh)/2;
    return max(queryTreeMax(ql, mid, l, h, 2*pos+1), queryTreeMax(mid+1, qh, l, h, 2*pos+2));
}

int buildMinTree(int l, int h, int pos){
    if(l == h){
        minTree[pos] = arr[l];
        return arr[l];
    }
    int mid = (l+h)/2;
    return minTree[pos] = min(
                   buildMinTree(l, mid, 2*pos+1),
                   buildMinTree(mid+1, h, 2*pos+2));
}

int buildMaxTree(int l, int h, int pos){
    if(l == h){
        maxTree[pos] = arr[l];
        return arr[l];
    }
    int mid = (l+h)/2;
    return maxTree[pos] = max(
                   buildMaxTree(l, mid, 2*pos+1),
                   buildMaxTree(mid+1, h, 2*pos+2));
}

int main(){
    int n, q, l, h;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    buildMinTree(0, n-1, 0);
    buildMaxTree(0, n-1, 0);
    cin>>q;
    int m, M, k, z;
    while(q--){
        cin>>l>>h;
        m = queryTreeMin(0, n-1, l, h, 0);
        M = queryTreeMax(0, n-1, l, h, 0);
        z = max(queryTreeMax(0, n-1, 0, l-1, 0), queryTreeMax(0, n-1, h+1, n-1, 0));
        k = (M-m)/2;
        cout<<m+max(k, z);
    }
    return 0;
}
