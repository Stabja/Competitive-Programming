#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long int ll;

int A[100001];
int B[100001];

int segTree1[1000001];
int segTree2[1000001];

int getMid(int s, int e){
    return s + (e -s)/2;
}

int getSumUtil(int ss, int se, int qs, int qe, int si, int z){
    if (qs <= ss && qe >= se){
        if(z == 1)
            return segTree1[si];
        else
            return segTree2[si];
    }
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    /*return getSumUtil(ss, mid, qs, qe, 2*si+1) +                //RangeSum
           getSumUtil(mid+1, se, qs, qe, 2*si+2);*/
    return max(getSumUtil(ss, mid, qs, qe, 2*si+1, z),       //RangeMaximum
               getSumUtil(mid+1, se, qs, qe, 2*si+2, z));
    /*return min(getSumUtil(ss, mid, qs, qe, 2*si+1),       //RangeMinimum
            getSumUtil(mid+1, se, qs, qe, 2*si+2));*/
}

int getSum(int n, int qs, int qe, int z){
    if (qs < 0 || qe > n-1 || qs > qe){
        return -1;
    }
    return getSumUtil(0, n-1, qs, qe, 0, z);
}

int constructSTUtil(int arr[], int ss, int se, int si, int z){
    if (ss == se){
        if(z == 1)
            segTree1[si] = arr[ss];
        else
            segTree2[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    /*segTree[si] =  constructSTUtil(arr, ss, mid, si*2+1) +            //RangeSum
                   constructSTUtil(arr, mid+1, se, si*2+2);*/
    if(z == 1)
        segTree1[si] = max(constructSTUtil(arr, ss, mid, si*2+1, z),    //RangeMaximum
                    constructSTUtil(arr, mid+1, se, si*2+2, z));
    else
        segTree2[si] = max(constructSTUtil(arr, ss, mid, si*2+1, z),    //RangeMaximum
                    constructSTUtil(arr, mid+1, se, si*2+2, z));
    /*segTree[si] = min(constructSTUtil(arr, ss, mid, si*2+1),    //RangeMinimum
                    constructSTUtil(arr, mid+1, se, si*2+2));*/
    if(z == 1)
        return segTree1[si];
    else
        return segTree2[si];
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>A[i];
    for(int i = 0; i < n; i++)
        cin>>B[i];

    for(int i = 0; i < n; i++){
        A[i] += i+1;
        B[i] += i+1;
    }

    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    constructSTUtil(A, 0, n-1, 0, 1);
    constructSTUtil(B, 0, n-1, 0, 2);
    /*for(int i = 0; i < max_size; i++){
        cout<<segTree1[i]<<" ";
    }
    cout<<"\n";
    for(int i = 0; i < max_size; i++){
        cout<<segTree2[i]<<" ";
    }*/
    ll sum1 = 0;
    ll sum2 = 0;
    for(int i = 0; i < n; i++){
        sum1 += A[i];
        sum2 += B[i];
    }
    cout<<1LL*sum1*sum2<<" ";
    sum1 = 0;
    sum2 = 0;
    for(int k = 1; k < n; k++){
        for(int i = 0; i < n-k; i++){      //N2LOGN
            sum1 += getSum(n, i, i+k, 1);
            sum2 += getSum(n, i, i+k, 2);
        }
        cout<<1LL*sum1*sum2<<" ";
        sum1 = 0;
        sum2 = 0;
    }
    return 0;
}
