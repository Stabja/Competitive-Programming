#include<stdio.h>
int main(){
    long long int T, n;
    scanf("%lld", &T);
    while(T--){
        scanf("%lld", &n);
        long long int gcd = 0, sum = 0;
        for(long long int j = 1; j <= n; j++){
            for(long long int i = 1 ; i <= j && i <= n; i++){
                if(j%i == 0 && n%i == 0 ){
                    gcd = i;
                }
            }
            sum += n/gcd;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
