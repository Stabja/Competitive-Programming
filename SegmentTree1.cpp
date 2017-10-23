#include<bits/stdc++.h>
using namespace std;

int segTree[1000001];
int arr[] = {34, 27, 14, 6, 8, 19, 4, 16, 24, 36, 23, 11,  9, 13,  5,  3, 41, 17, 27, 15};

int getMid(int s, int e){
    return s + (e -s)/2;
}

int getSumUtil(int ss, int se, int qs, int qe, int si){
    if (qs <= ss && qe >= se)
        return segTree[si];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +                //RangeSum
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
    /*return max(getSumUtil(ss, mid, qs, qe, 2*si+1),       //RangeMaximum
            getSumUtil(mid+1, se, qs, qe, 2*si+2));*/
    /*return min(getSumUtil(ss, mid, qs, qe, 2*si+1),       //RangeMinimum
            getSumUtil(mid+1, se, qs, qe, 2*si+2));*/
}

int getSum(int n, int qs, int qe){
    if (qs < 0 || qe > n-1 || qs > qe){
        return -1;
    }
    return getSumUtil(0, n-1, qs, qe, 0);
}

int constructSTUtil(int ss, int se, int si){
    if (ss == se){
        segTree[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    segTree[si] =  constructSTUtil(ss, mid, si*2+1) +            //RangeSum
                   constructSTUtil(mid+1, se, si*2+2);
    /*segTree[si] = max(constructSTUtil(arr, ss, mid, si*2+1),    //RangeMaximum
                    constructSTUtil(arr, mid+1, se, si*2+2));*/
    /*segTree[si] = min(constructSTUtil(arr, ss, mid, si*2+1),    //RangeMinimum
                    constructSTUtil(arr, mid+1, se, si*2+2));*/
    return segTree[si];
}

void display(int max_size){
    for(int i = 0; i < max_size; i++){
        cout<<segTree[i]<<" ";
    }
}

int main()
{
    /////////////01, 02, 03, 4, 5, 06, 7, 08, 09, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    constructSTUtil(0, n-1, 0);
    //display();
    int q, l, r;
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<getSum(n, l-1, r-1)<<"\n";
    }
    return 0;
}
