#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

bool compare(int i, int j){
    return (i < j);
}

int main(){
    int m, n, a[100000];
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &a[i]);
    }
    int best = 10000;
    sort(a, a + m, compare);
    for(int i = 0; i <= m-n; i++){
        best = min(best, a[i + n - 1] - a[i]);
    }
    printf("%d", best);
    return 0;
}
