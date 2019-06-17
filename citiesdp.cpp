#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int A[] = {8,10,4,6,5,9,2};

int compute(int i, int k, int ans, int n){
    if(i > n) return ans;
    int x = i+(i%k)+1;
    if(x == i+1 || x > n){
        ans += compute(i+1, k, A[i-1], n);
    }else{
        ans += min(compute(i+1, k, A[i-1], n), compute(x, k, A[i-1], n));
    }
    return ans;
}

int main() {
    int n = 7;
    int k = 2;
    cout<<compute(1, k, 0, n);
    return 0;
}