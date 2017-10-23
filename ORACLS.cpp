#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int t, m, n, N;
    cin>>t;
    while(t--){
        string str[100];
        cin>>N;
        for(int i = 0; i < N; i++){
            cin>>str[i];
        }
        int m = str[0].length();
        int numA = 0, numB = 0, smallA = 10000, smallB = 10000;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < m; j++){
                if(str[i][j] == 'a')
                    numA++;
                else
                    numB++;
            }
            if(numA < smallA)
                smallA = numA;
            if(numB < smallB)
                smallB = numB;
            numA = 0;
            numB = 0;
        }
        cout<<min(smallA, smallB)<<"\n";
    }
    return 0;
}
