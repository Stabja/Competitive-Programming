#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000009
#define LL long long int
#define mp make_pair
#define pb push_back

int a1[100005];
int a2[100005];
int a3[100005];
int sh[10000005];

int main(){
    int n1, n2, n3;
    cin>>n1>>n2>>n3;
        for(int i = 0; i < n1; i++){
            cin>>a1[i];
        }
        for(int i = 0; i < n2; i++){
            cin>>a2[i];
        }
        for(int i = 0; i < n3; i++){
            cin>>a3[i];
        }
        for(int i = n1-2; i>=0; --i){
            a1[i] += a1[i+1];
        }
        for(int i = n2-2; i>=0; --i){
            a2[i] += a2[i+1];
        }
        for(int i = n3-2; i>=0; --i){
            a3[i] += a3[i+1];
        }
        for(int i = 0; i < n1; i++){
            sh[a1[i]]++;
        }
        for(int i = 0; i < n2; i++){
            sh[a2[i]]++;
        }
        for(int i = 0; i < n3; i++){
            sh[a3[i]]++;
        }
        int flag = 0;
        for(int i = 9999999; i >= 0; i--){
            if(sh[i] >= 3){
               cout<<i;
               flag = 1;
               break;
            }
        }
        if(flag == 0){
            cout<<0;
        }
    return 0;
}
