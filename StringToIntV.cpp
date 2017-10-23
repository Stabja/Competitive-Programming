#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair

int arr[10000005];
int tree[20000005];
int lazy[20000005];

int getSumUtil(int ss, int se, int qs, int qe, int si){
    if (lazy[si] != 0){
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se){
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

int getSum(int n, int qs, int qe){
    if (qs < 0 || qe > n-1 || qs > qe){
        printf("Invalid Input");
        return -1;
    }
    return getSumUtil(0, n-1, qs, qe, 0);
}

void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff){
    if (lazy[si] != 0){
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2 + 1]  += lazy[si];
            lazy[si*2 + 2]  += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>ue || se<us)
        return ;
    if (ss>=us && se<=ue){
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

void updateRange(int n, int us, int ue, int diff){
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}

/*int getSum(int l, int r, int cl, int cr, int i){
    if(l <= cl && r >= cr){
        return tree[i];
    }
    if(cl < l && cr < l || cl > r && cr > r){
        return 0;
    }
    int mid = (cl + cr)/2;
    return getSum(l, r, cl, mid, 2*i+1) + getSum(l, r, mid+1, cr, 2*i+2);
}*/

int buildTree(int l, int r, int i){
    if(l == r){
        tree[i] = arr[l];
        return tree[i];
    }
    int mid = (l+r)/2;
    tree[i] = buildTree(l, mid, 2*i+1) + buildTree(mid+1, r, 2*i+2);
    return tree[i];
}

int main(){
    //buildTree(0, n-1, 0);
    //updateRange(n, 1, 5, 10);
    //getSum(n, 1, 3);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        updateRange(n, a-1, b-1, k);
    }
    int maxVal = 0;
    for(int i = 0; i < n; i++){
        maxVal = max(maxVal, getSum(n, i, i));
    }
    cout<<maxVal<<"\n";
    return 0;
}
