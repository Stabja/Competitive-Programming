#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n, a[100], b[100], cnt = 0, maxcnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    //Create Array B
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            b[i] = 1;
        }
        else{
            b[i] == -1;
        }
    }
    return 0;
}
