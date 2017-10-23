#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 100002

int arr[MAXN];
int segTree[4*MAXN];
int lazy1[4*MAXN];
int lazy2[4*MAXN];
bool lazy[4*MAXN];

const int mod = 1000000007;

void updateMul(int si, int ss, int se, int us, int ue, int diff)
{
    if (lazy[si])         //Previous update
    {
        segTree[si] = (segTree[si]*lazy2[si] + (se-ss+1)*lazy1[si]);
        if (ss != se)
        {
            lazy[2*si + 1] = lazy[2*si + 2] = true;
            lazy2[si*2 + 1] *= lazy2[si];
            lazy2[si*2 + 2] *= lazy2[si];
            lazy1[si*2 + 1] = lazy1[si*2 + 1]*lazy2[si] + lazy1[si];
            lazy1[si*2 + 2] = lazy1[si*2 + 2]*lazy2[si] + lazy1[si];
        }
        lazy[si] = false;
        lazy2[si] = 1;
        lazy1[si] = 0;
    }

    if (ss>se || ss>ue || se<us)      //No overlap
        return ;

    if (ss>=us && se<=ue)            //Total overlap
    {
        segTree[si] *= diff;
        if (ss != se)
        {
            lazy[2*si + 1] = lazy[2*si + 2] = true;
            lazy2[si*2 + 1] *= diff;
            lazy2[si*2 + 2] *= diff;
            lazy1[si*2 + 1] *= diff;
            lazy1[si*2 + 2] *= diff;
        }
        return;
    }
    int mid = (ss+se)/2;             //Partial overlap
    updateMul(si*2+1, ss, mid, us, ue, diff);
    updateMul(si*2+2, mid+1, se, us, ue, diff);
    segTree[si] = segTree[si*2+1] + segTree[si*2+2];
}

void updateAdd(int si, int ss, int se, int us, int ue, int diff)
{
    if (lazy[si])
    {
        segTree[si] = (segTree[si]*lazy2[si] + (se-ss+1)*lazy1[si]);
        if (ss != se)
        {
            lazy[2*si + 1] = lazy[2*si + 2] = true;
            lazy2[si*2 + 1] *= lazy2[si];
            lazy2[si*2 + 2] *= lazy2[si];
            lazy1[si*2 + 1] = lazy1[si*2 + 1]*lazy2[si] + lazy1[si];
            lazy1[si*2 + 2] = lazy1[si*2 + 2]*lazy2[si] + lazy1[si];
        }
        lazy[si] = false;
        lazy2[si] = 1;
        lazy1[si] = 0;
    }
    if (ss>se || ss>ue || se<us)
        return ;

    if (ss>=us && se<=ue)
    {
        segTree[si] += (se-ss+1)*diff;
        if (ss != se)
        {
            lazy[si*2 + 1] = lazy[si*2 + 2] = true;
            lazy1[si*2 + 1] += diff;
            lazy1[si*2 + 2] += diff;
        }
        return;
    }
    int mid = (ss+se)/2;
    updateAdd(si*2+1, ss, mid, us, ue, diff);
    updateAdd(si*2+2, mid+1, se, us, ue, diff);
    segTree[si] = segTree[si*2+1] + segTree[si*2+2];
}

void updateReplace(int si, int ss, int se, int us, int ue, int diff)
{
    if (lazy[si])
    {
        segTree[si] = (segTree[si]*lazy2[si] + (se-ss+1)*lazy1[si]);
        if (ss != se)
        {
            lazy[2*si + 1] = lazy[2*si + 2] = true;
            lazy2[si*2 + 1] *= lazy2[si];
            lazy2[si*2 + 2] *= lazy2[si];
            lazy1[si*2 + 1] = lazy1[si*2 + 1]*lazy2[si] + lazy1[si];
            lazy1[si*2 + 2] = lazy1[si*2 + 2]*lazy2[si] + lazy1[si];
        }
        lazy[si] = false;
        lazy2[si] = 1;
        lazy1[si] = 0;
    }
    if (ss>se || ss>ue || se<us)
        return ;

    if (ss>=us && se<=ue)
    {
        segTree[si] = (se-ss+1)*diff;
        if (ss != se)
        {
            lazy[2*si + 1] = lazy[2*si + 2] = true;
            lazy2[si*2 + 1] = lazy2[si*2 + 2] = 0;
            lazy1[si*2 + 1] = lazy1[si*2 + 2] = diff;
        }
        return;
    }
    int mid = (ss+se)/2;
    updateAdd(si*2+1, ss, mid, us, ue, diff);
    updateAdd(si*2+2, mid+1, se, us, ue, diff);
    segTree[si] = segTree[si*2+1] + segTree[si*2+2];
}

/*void updateElement(int pos, int i, int val, int s, int e){
    if(i < s || i > e){
        return;
    }l>>h<<del;
    st[pos] += val;
    if(s != e){
        int mid = (s+e)/2;
        updateElement(2*pos+1, i, val, s, mid);
        updateElement(2*pos+2, i, val, mid+1, e);
    }
}*/

int buildTree(int arr[], int l, int h, int pos){
    if(l == h){
        segTree[pos] = arr[l];
        return arr[l];
    }
    int mid = (l+h)/2;
    return segTree[pos] = buildTree(arr, l, mid, 2*pos+1) +
                   buildTree(arr, mid+1, h, 2*pos+2);
}

/*int queryTree(int ql, int qh, int l, int h, int pos){
    //Check if complete overlap
    if(l <= ql && h >= qh){
        return segTree[pos];
    }
    //Check if no overlap
    if(qh < l || ql > h ){         //Give this condition properly
        return 0;
    }
    //If partial overlap
    int mid = (ql+qh)/2;
    return queryTree(ql, mid, l, h, 2*pos+1) +
           queryTree(mid+1, qh, l, h, 2*pos+2);
}*/

int getSum(int ss, int se, int qs, int qe, int si)
{
    if (lazy[si])
    {
        segTree[si] = (segTree[si]*lazy2[si] + (se-ss+1)*lazy1[si]);
        if (ss != se)
        {
            lazy[2*si + 1] = lazy[2*si + 2] = true;
            lazy2[si*2 + 1] *= lazy2[si];
            lazy2[si*2 + 2] *= lazy2[si];
            lazy1[si*2 + 1] = lazy1[si*2 + 1]*lazy2[si] + lazy1[si];
            lazy1[si*2 + 2] = lazy1[si*2 + 2]*lazy2[si] + lazy1[si];

        }
        lazy[si] = false;
        lazy2[si] = 1;
        lazy1[si] = 0;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;

    if (ss>=qs && se<=qe)
        return segTree[si];

    int mid = (ss + se)/2;
    return getSum(ss, mid, qs, qe, 2*si+1) +
           getSum(mid+1, se, qs, qe, 2*si+2);
}

void Display(int m){
    for(int i = 0; i < m; i++){
        cout<<segTree[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int N, Q;
    cin>>N>>Q;
    for(int i = 0; i < N ;i++){
        cin>>arr[i];
    }
    int p = (int)(ceil(log2(N)));           //Height of segment tree
    int max_size = 2*(int)pow(2, p) - 1;    //Max size of segment tree
    buildTree(arr, 0, N-1, 0);          //Start from position 0 of the segment tree
    //Display(max_size);
    for(int i = 0; i < 4*MAXN; i++){
        lazy2[i] = 1;
    }
    memset(lazy, false, sizeof lazy);
    int c, x, y, v;
    while(Q--){
        cin>>c;
        if(c == 1){
            cin>>x>>y>>v;
            updateAdd(0, 0, N-1, x-1, y-1, v);
        }
        else if(c == 2){
            cin>>x>>y>>v;
            updateMul(0, 0, N-1, x-1, y-1, v);
        }
        else if(c == 3){
            cin>>x>>y>>v;
            updateReplace(0, 0, N-1, x-1, y-1, v);
        }
        else if(c == 4){
            cin>>x>>y;
            cout<<getSum(0, N-1, x-1, y-1, 0)<<"\n";
        }
        //Display(max_size);
    }
    return 0;
}
