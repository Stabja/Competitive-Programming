#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int tree[300000];
bool lazy[300000];

void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff)
{
    if (lazy[si])         //If updates not applied, apply and propagate to children
    {
        //tree[si] += (se-ss+1)*lazy[si];
        tree[si] = (se-ss+1) - tree[si];
        if(ss != se)           //If not leaf node, then propagate
        {
            lazy[si*2 + 1] = !lazy[si*2 + 1];
            lazy[si*2 + 2] = !lazy[si*2 + 2];
        }
        lazy[si] = false;          //Revert
    }

    if (ss>se || ss>ue || se<us)   //No overlap
        return ;

    if (ss>=us && se<=ue)          //Total overlap
    {
        tree[si] = (se-ss+1) - tree[si];
        if (ss != se)
        {
            lazy[si*2 + 1] = !lazy[si*2 + 1];
            lazy[si*2 + 2] = !lazy[si*2 + 2];
        }
        return;
    }
    int mid = (ss + se)/2;              //Partial overlap
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
    if (lazy[si])       //If updates not applied, apply and propagate to children
    {
        tree[si] = (se-ss+1) - tree[si];
        if(ss != se)           //If not leaf node, then propagate
        {
            lazy[si*2 + 1] = !lazy[si*2 + 1];
            lazy[si*2 + 2] = !lazy[si*2 + 2];
        }
        lazy[si] = false;          //Revert
    }

    if (ss>se || ss>qe || se<qs)      //No overlap
        return 0;

    if (ss>=qs && se<=qe)             //Total overlap
        return tree[si];

    int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}

int getSum(int n, int qs, int qe)
{
    if(qs < 0 || qe > n-1 || qs > qe)
        return -1;
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

void display(int n){
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    for(int i = 0; i < max_size; i++){
        cout<<tree[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int N, Q;
    cin>>N>>Q;
    int k, a, b;
    //constructBITree(coins, N);
    while(Q--){
        cin>>k>>a>>b;
        if(k == 0){
            updateRange(N, a, b, 0);
            //display(N);
        }
        else{
            cout<<getSum(N, a, b)<<"\n";
            //display(N);
        }
    }
    return 0;
}
