#include<bits/stdc++.h>
using namespace std;

int main(){
    int T, N, M, cnt = 0;
    cin>>T;
    while(T--){
        cin>>N>>M;
        if(M < N-1 || M > N*(N-1)/2 ){
            cout<<"-1"<<" "<<"-1"<<"\n";
            continue;
        }
        for(int i = 1; i < (N+1)/2; i++){
            for(int j = 1; j <= N; j++){

                if((i+j) <= N)
                    cout<<j<<" "<<(j+i)<<"\n";
                else
                    cout<<j<<" "<<(j+i)%N<<"\n";
            }
        }
        cnt = 0;
        /*for(int i = 1; i < N; i++){
            for(int j = 1; j <= N; j++){
                if(i+j > N)
                    continue;
                if(i >= N-1)
                    continue;
                cout<<j<<" "<<j+i<<"\n";
            }
        }*/
    }
    return 0;
}
