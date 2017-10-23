#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000007
#define LL long long int

#ifndef ONLINE_JUDGE
	#define gc getchar
#else
	#define gc getchar_unlocked
#endif

struct node{
    LL f1;
    LL f2;
    LL f3;
    LL f4;
};

void multiply(int F[2][2], int M[2][2]);
void power(int F[2][2], int n);

inline int read(){
	int res = 0,sign = 1;
	char c = gc();
	while(!(c>='0' && c<='9')){
		if(c=='-')
		sign = -1;
		c = gc();
	}
	while(c>='0' && c<='9'){
		res = (res<<3)+(res<<1)+c-'0';
		c = gc();
	}
	return res*sign;
}

node segTree[300005];
int arr[100005];

void matmult(LL a[][2], LL b[][2], LL c[][2]){
    int i,j,k;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            c[i][j]=0;
            for(k=0;k<2;k++){
                c[i][j]+=(a[i][k]*b[k][j]);
                c[i][j]=c[i][j]%MAXX;
            }
        }
    }
}

void matpow(LL Z[][2], int n, LL ans[][2]){
    LL temp[2][2];
    ans[0][0]=1;
    ans[1][0]=0;
    ans[0][1]=0;
    ans[1][1]=1;
    int i,j;
    while(n>0){
        if(n&1){
            matmult(ans,Z,temp);
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    ans[i][j]=temp[i][j];
        }
        matmult(Z,Z,temp);
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                Z[i][j]=temp[i][j];
        n=n/2;
    }
    return;
}

LL fib(LL n){
    n++;
    LL fib;
    if(n>2){
        LL Z[2][2]={{1,1},{1,0}},result[2][2];
        matpow(Z,n-2,result);
        fib=result[0][0]*1 + result[0][1]*0;
    }
    else
        fib=n-1;
    return fib;
}

int getMid(int s, int e){
    return s + (e -s)/2;
}

node getSumUtil(int ss, int se, int qs, int qe, int si){
    if(qs <= ss && qe >= se){
        return segTree[si];
    }
    if(se < qs || ss > qe){
        node temp;
        temp.f1 = 1;
        temp.f2 = 0;
        temp.f3 = 0;
        temp.f4 = 1;
        return temp;
    }
    int mid = getMid(ss, se);
    node left = getSumUtil(ss, mid, qs, qe, 2*si+1);
    node right = getSumUtil(mid+1, se, qs, qe, 2*si+2);
    node ans;
    ans.f1 = ((left.f1%MAXX*right.f1%MAXX)%MAXX + (left.f2%MAXX*right.f3%MAXX)%MAXX)%MAXX;
    ans.f2 = ((left.f1%MAXX*right.f2%MAXX)%MAXX + (left.f2%MAXX*right.f4%MAXX)%MAXX)%MAXX;
    ans.f3 = ans.f2;
    //ans.f3 = ((left.f3%MAXX*right.f1%MAXX)%MAXX + (left.f4%MAXX*right.f3%MAXX)%MAXX)%MAXX;
    ans.f4 = ((left.f3%MAXX*right.f2%MAXX)%MAXX + (left.f4%MAXX*right.f4%MAXX)%MAXX)%MAXX;
    return ans;

}

LL getSum(int n, int qs, int qe){
    if (qs < 0 || qe > n-1 || qs > qe){
        return -1;
    }
    return getSumUtil(0, n-1, qs, qe, 0).f2;
}

node constructSTUtil(int ss, int se, int si){
    if (ss == se){                          //If leaf node
        segTree[si].f1 = (fib(arr[ss]+1)+1);
        segTree[si].f2 = fib(arr[ss]);
        segTree[si].f3 = segTree[si].f2;
        segTree[si].f4 = (fib(arr[ss]-1)+1);
        return segTree[si];
    }
    int mid = getMid(ss, se);
    node left = constructSTUtil(ss, mid, si*2+1);
    node right = constructSTUtil(mid+1, se, si*2+2);
    segTree[si].f1 = ((left.f1%MAXX*right.f1%MAXX)%MAXX + (left.f2%MAXX*right.f3%MAXX)%MAXX)%MAXX;
    segTree[si].f2 = ((left.f1%MAXX*right.f2%MAXX)%MAXX + (left.f2%MAXX*right.f4%MAXX)%MAXX)%MAXX;
    segTree[si].f3 = segTree[si].f2;
    //segTree[si].f3 = ((left.f3%MAXX*right.f1%MAXX)%MAXX + (left.f4%MAXX*right.f3%MAXX)%MAXX)%MAXX;
    segTree[si].f4 = ((left.f3%MAXX*right.f2%MAXX)%MAXX + (left.f4%MAXX*right.f4%MAXX)%MAXX)%MAXX;
    return segTree[si];
}

void display(int siz){
    for(int i = 0; i < siz; i++){
        cout<<segTree[i].f2<<" ";
    }
    cout<<"\n";
}

int main(){
    int n, q;
    n = read();
    q = read();
    for(int i = 0; i < n; i++){
        arr[i] = read();
    }
    //int x = (int)(ceil(log2(n)));
    //int max_size = 2*(int)pow(2, x) - 1;
    constructSTUtil(0, n-1, 0);
    //display(max_size);
    while(q--){
        char ch;
        int l, r;
        cin>>ch;
        l = read();
        r = read();
        if(ch == 'Q'){
            cout<<getSum(n, l-1, r-1)<<"\n";
        }
    }
    return 0;
}




