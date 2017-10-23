#include<stdio.h>

int main(){
    long long int n, a[100000], cnt = 0, maxsub = 0;
    scanf("%I64d", &n);
    for(long long int i = 0; i < n; i++){
        scanf("%I64d", &a[i]);
    }
    for(long long int i = 0; i < n; i++){
        cnt++;
        if(a[i+1] < a[i]){
            if(cnt > maxsub){
                maxsub = cnt;
            }
            cnt = 0;
        }
    }
    printf("%I64d", maxsub);
    return 0;
}
