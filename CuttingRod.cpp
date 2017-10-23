#include<iostream>
using namespace std;

int main(){
    int V[] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    int B[100];
    for(int i = 0; i < 100; i++){
       B[i] = 0;
    }
    int maxx = 0, tmp = 0;;
    B[0] = 0;
    for(int i = 1; i <= 8; i++){
            maxx = 0;
            tmp = 0;
        for(int j = 0; j <= i; j++){
            tmp = V[j] + B[i-j];        //Dynamic Formula
            if(tmp > maxx){
                maxx = tmp;
            }
        }
        B[i] = maxx;
    }
    for(int i = 0; i <= 8; i++){
        cout<<B[i]<<" ";
    }
    return 0;
}
