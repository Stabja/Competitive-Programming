#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string str1, str2;
    int m, n, T[100][100];
    cin>>str1>>str2;
    m = str1.length()+1;
    n = str2.length()+1;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(str1[j-1] == str2[i-1]){
                T[i][j] = T[i-1][j-1]+1;
            }
            else{
                T[i][j] = max(T[i-1][j], T[i][j-1]);
            }
        }
    }
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<T[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    cout<<T[n-1][m-1];
    return 0;
}
