#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int Mat[100][100];
int sum[10001];
int cnt[10001];

int main(){
    int T;
    cin>>T;
    while(T--){
        int N, M, K;
        cin>>N>>M>>K;
        int z = K;
        while(z--){
            int x;
            cin>>x;
            x--;
            Mat[x/M][x%M] = 1;
        }
        /*for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cout<<Mat[i][j]<<" ";
                Mat[i][j] = 0;
            }
            cout<<"\n";
        }*/
        int k = 0;
        for(int l = 1; l <= N; l++){
            for(int b = 1; b <= M; b++){
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < M; j++){
                        if(i+l > N || j+b > M)
                            continue;

                        for(int p = 0; p < l; p++){
                            for(int q = 0; q < b; q++){
                                sum[k] += Mat[i+p][j+q];
                            }
                        }
                        k++;
                    }
                }
            }
        }

        /*for(int i = 0; i < k; i++){
            cout<<sum[i]<<" ";
        }*/
        int total = k;
        for(int i = 0; i < k; i++){
            cnt[sum[i]]++;
        }
        double ans = 0;
        for(int i = 0; i <= K; i++){
            //cout<<cnt[i]<<" ";
            ans += (float)((float)i*(float)cnt[i]/(float)total);
        }
        cout<<setprecision(16)<<ans<<"\n";
        memset(sum, 0, sizeof sum);
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++)
                Mat[i][j] = 0;
        }
    }
    return 0;
}

