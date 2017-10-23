#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int Iset[10000];
int Nset[100001];
int Wset[100001];

int T[40][100004];
int segTree[40][1000001];

int getMid(int s, int e){
    return s + (e -s)/2;
}

int getSumUtil(int ss, int se, int qs, int qe, int si, int bit){
    if (qs <= ss && qe >= se)
        return segTree[bit][si];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return getSumUtil(ss, mid, qs, qe, 2*si+1, bit) +                //RangeSum
           getSumUtil(mid+1, se, qs, qe, 2*si+2, bit);
}

int getSum(int n, int qs, int qe, int bit){
    if (qs < 0 || qe > n-1 || qs > qe){
        return -1;
    }
    return getSumUtil(0, n-1, qs, qe, 0, bit);
}

int constructSTUtil(int bit, int ss, int se, int si){
    if (ss == se){
        segTree[bit][si] = T[bit][ss];
        return T[bit][ss];
    }
    int mid = getMid(ss, se);
    segTree[bit][si] =  constructSTUtil(bit, ss, mid, si*2+1) +            //RangeSum
                        constructSTUtil(bit, mid+1, se, si*2+2);
    return segTree[bit][si];
}

void computebinary(int k, int x){
    if(x == 0)
        return;
    int y = log2(x);
    T[y][k] = 1;
    if(y == 0)
        return;
    computebinary(k, x-pow(2, y));
}

int main(){
    int K, P, Q;
    cin>>K>>P>>Q;
    for(int i = 0; i < K; i++){
        cin>>Iset[i];
    }
    for(int i = 0; i < P; i++){
        cin>>Nset[i];
    }
    for(int i = 0; i < P; i++){
        for(int j = 0; j < K; j++){
            if(Nset[i]%Iset[j] == 0){
                Wset[i] = Iset[j];
            }
        }
    }
    /*for(int i = 0; i < P; i++){
        cout<<Wset[i]<<" ";          //CONVERT ALL THE NOS OF WSET TO BINARY
    }*/
    int x = (int)(ceil(log2(P)));
    int max_size = 2*(int)pow(2, x) - 1;

    for(int i = 0; i < P; i++){
        computebinary(i, Wset[i]);
    }
    for(int i = 0; i < 40; i++){
        constructSTUtil(i, 0, P-1, 0);
    }
    /*for(int i = 0; i < 10; i++){
        for(int j = 0; j < P; j++){
            cout<<T[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < max_size; j++){
            cout<<segTree[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    cout<<"\n";
    while(Q--){
        int L, R;
        cin>>L>>R;
        long long int Total = 0;
        for(int j = 0; j < 40; j++){
            int sum = getSum(P, L, R, j);
            Total += 1LL*sum*(sum-1)*pow(2, j)/2;
        }
        cout<<Total<<"\n";
    }
    return 0;
}
