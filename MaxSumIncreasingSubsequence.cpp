#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, input[100], T[100], sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &input[i]);
    }
    for(int i = 0; i < n; i++){
        T[i] = input[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(input[j] < input[i]){
                T[i] = max(T[i], T[j] + input[i]);
            }
        }
    }
    //Find the max element in T
    for(int i = 0; i < n; i++){
        if(T[i] > sum){
            sum = T[i];
        }
    }
    printf("%d", sum);
    return 0;
}
