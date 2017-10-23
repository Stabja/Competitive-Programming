#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char arr[30][30];
vector<pair<int, int> > places;

int min(int a, int b)
{ return (a < b)? a: b; }

int min(int a, int b, int c)
{ return min(min(a, b), c);}

int max(int a, int b)
{ return (a > b)? a: b; }

int main(){
    int T, N, K;
    cin>>T;
    while(T--){
        cin>>N>>K;
        for(int i = 0; i < N; i++){
            for(int j = 0 ; j < N; j++){
                cin>>arr[i][j];
                if(arr[i][j] == '.'){
                    places.push_back(make_pair(i, j));
                }
            }
        }
        int flag = 0;
        for(int c = 0; c < places.size(); c++){
            arr[places[c].first][places[c].second] = 'X';
            for(int i = 0; i < N; i++){          ////////ROWS
                int cnt = 0;
                for(int j = 0; j < N; j++){
                    if(arr[i][j] == 'X'){
                        cnt++;
                    }
                }
                if(cnt >= K){
                    flag = 1;
                    cout<<"YES\n";
                    break;
                }
            }
            if(flag == 0){              ////////COLUMNS
                for(int i = 0; i < N; i++){
                    int cnt = 0;
                    for(int j = 0; j < N; j++){
                        if(arr[j][i] == 'X'){
                            cnt++;
                        }
                    }
                    if(cnt >= K){
                        flag = 1;
                        cout<<"YES\n";
                        break;
                    }
                }
            }
            if(flag == 0){             ////////DIAGONAL1
                for (int line=1; line<=(N + N -1); line++)
                {
                    int start_col =  max(0, line-N);
                    int coun = min(line, (N-start_col), N);
                    if(coun < K)
                        continue;
                    int cnt = 0;
                    for(int j=0; j<coun; j++){
                        //printf("%5d ", matrix[start_col+j][min(N, line)-j-1]);
                        if(arr[start_col+j][min(N, line)-j-1] == 'X'){
                            cnt++;
                        }
                    }
                    //printf("\n");
                    if(cnt >= K){
                        flag = 1;
                        cout<<"YES\n";
                        break;
                    }
                }
            }
            if(flag == 0){             /////////DIAGONAL2
                for (int line=1; line<=(N + N -1); line++)
                {
                    int start_col =  max(0, line-N);
                    int coun = min(line, (N-start_col), N);
                    if(coun < K)
                        continue;
                    int cnt = 0;
                    for(int j=0; j<coun; j++){
                        //printf("%5d ", matrix[start_col+j][min(N, line)-j-1]);
                        if(arr[start_col+j][N-1-(min(N, line)-j-1)] == 'X'){
                            cnt++;
                        }
                    }
                    //printf("\n");
                    if(cnt >= K){
                        flag = 1;
                        cout<<"YES\n";
                        break;
                    }
                }
            }
            if(flag == 1)
                break;
            arr[places[c].first][places[c].second] = '.';
        }
        if(flag == 0)
            cout<<"NO\n";
    }
    return 0;
}
