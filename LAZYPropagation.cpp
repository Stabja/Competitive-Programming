#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

#define MAX 100001

int tree[MAX] = {0};
int lazy[MAX] = {0};

void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>ue || se<us)
        return ;

    if (ss>=us && se<=ue)
    {
        tree[si] += (se-ss+1)*diff;
        if (ss != se)
        {
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }
    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
    tree[si] = tree[si*2+1] + tree[si*2+2];
}

void updateRange(int n, int us, int ue, int diff)
{
    updateRangeUtil(0, 0, n-1, us, ue, diff);
}

int getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;

    if (ss>=qs && se<=qe)
        return tree[si];

    int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}

int getSum(int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
    return getSumUtil(0, n-1, qs, qe, 0);
}

void constructSTUtil(int arr[], int ss, int se, int si)
{
    if (ss > se)
        return ;
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }
    int mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);

    tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
}

void constructST(int arr[], int n)
{
    constructSTUtil(arr, 0, n-1, 0);
}

int main()
{
    int arr[] = {4, 1, 5, 8, 7, 2, 6, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    constructST(arr, n);
    /*cout<<getSum(n, 2, 5)<<"\n";
    updateRange(n, 1, 6, 3);
    cout<<getSum(n, 2, 5)<<"\n";*/
    int q;
    cin>>q;
    int k, a, b, d;
    while(q--){
        cin>>k;
        if(k == 0){
            cin>>a>>b;
            cout<<getSum(n, a, b)<<"\n";
        }
        else{
            cin>>a>>b>>d;
            updateRange(n, a, b, d);
            cout<<getSum(n, a, b)<<"\n";
        }
    }
    return 0;
}
