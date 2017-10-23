#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, a[100];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int times = pow(2, n);
    for(int i = 0; i < times; i++){
        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                cout<<a[j]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
