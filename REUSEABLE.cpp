#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int T, N, M, cnt = 0;
    cin>>T;
    while(T--){
        cin>>N>>M;
        if(N <= 2){
            cout<<-1<<" "<<-1<<"\n";
        }
        else if(N > 2 && N <= 4 && N != M){
            cout<<-1<<" "<<-1<<"\n";
        }
        else if(N > 2 && N <= 4 && N == M){
            //cout<<"yeah bitch";
            for(int i = 1; i < N; i++){
                for(int j = 1; j <= N; j++){
                    cnt++;
                    if(cnt > M)
                        break;
                    if((i+j) <= N)
                        cout<<j<<" "<<(j+i)<<"\n";
                    else
                        cout<<j<<" "<<(j+i)%N<<"\n";
                }
            }
            cnt = 0;
        }
        else if(N > 4 && M < N){
            cout<<-1<<" "<<-1<<"\n";
        }
        else{
            for(int i = 1; i < N; i++){
                for(int j = 1; j <= N; j++){
                    cnt++;
                    if(cnt > M)
                        break;
                    if((i+j) <= N)
                        cout<<j<<" "<<(j+i)<<"\n";
                    else
                        cout<<j<<" "<<(j+i)%N<<"\n";
                }
            }
            cnt = 0;
        }
    }
    return 0;
}
