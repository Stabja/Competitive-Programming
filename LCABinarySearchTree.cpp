#include<bits/stdc++.h>
using namespace std;

int tree[1000];
int pptr[1000];

int LCA(int root, int a, int b){
    int left = 2*root+1;
    int right = 2*root+2;
    if(tree[root] > a && tree[root] > b){
        return LCA(left, a, b);
    }
    if(tree[root] < a && tree[root] < b){
        return LCA(right, a, b);
    }
    return root;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>tree[i];
    }
    int q;
    cin>>q;
    int x, y;
    while(q--){
        cin>>x>>y;
        int ancestor = LCA(0, x, y);
        cout<<ancestor<<" "<<tree[ancestor]<<"\n";
    }
    return 0;
}
