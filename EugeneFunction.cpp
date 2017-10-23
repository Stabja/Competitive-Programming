#include<stdio.h>

int compute(long long int x){
    if(x < 10){
        return x;
    }
    long long int k = x;
    int sum = 0;
    while(k != 0){
        sum += k%10;
        k = k/10;
    }
    x = sum;
    return compute(sum);
}

int main(){
    long T;
    long long int A1, D, L, R;
    scanf("%ld", &T);
    while(T--){
        int sum = 0;
        scanf("%lld%lld%lld%lld", &A1, &D, &L, &R);
        for(int i = L; i <= R; i++){
            sum += compute(A1 + (i-1)*D);
        }
        printf("%d\n", sum);
    }
    return 0;
}
