#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int N, M;
//int tree[200][200];
//int Mat[200][200];
int arr[100001];
int *Mat = new int[100000*10000000];
int *tree = new int[10000000*10000000];

/*void update(int x , int y , int val){
    while (x <= max_x){
        updatey(x , y , val);   // this function should update array tree[x]
        x += (x & -x);
    }
}

void updatey(int x , int y , int val){
    while (y <= max_y){
        tree[x][y] += val;
        y += (y & -y);
    }
}*/

void update(int x , int y , int val){
    int y1;
    while (x <= N){
        y1 = y;
        while (y1 <= M){
            //tree[x][y1] += val;
            tree[x*N+y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

int read(int x,int y){     // return sum from 1,1 to x,y.
    int sum= 0;
    while(x){
        int y1 = y;
        while(y1){
            //sum += tree[x][y1];
            sum += tree[x*N+y1];
            y1 -= y1 & -y1;
        }
        x -= x & -x;
    }
    return sum;
}

int rectangle(int x1, int y1, int x2, int y2){
    int k = read(x2, y2)-read(x2, y1)-read(x1, y2)+read(x1, y1);
    return k;
}

int main(){
    /*int T[6][6] = {{1, 1, 1, 0, 1, 0},
                   {1, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0},
                   {0, 0, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0},
                   {0, 0, 1, 0, 1, 0},
                  };
    int T[2][2] = {{1, 1},
                   {0, 0}
                  };
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= 2; j++){
            update(i, j, T[i-1][j-1]);
        }
    }
    cout<<rectangle(1, 1, 2, 2);*/

    int T;
    cin>>T;
    while(T--){
        int K;
        cin>>N>>M>>K;
        memset(arr, 0, sizeof arr);
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= M; j++){
                //Mat[i][j] = 0;
                Mat[i*N+j] = 0;
                tree[i*N+j] = 0;
            }
        }
        int z = K;
        while(z--){
            int x;
            cin>>x;
            x--;
            //Mat[x/M][x%M] = 1;
            Mat[x*N/M+x%M] = 1;
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                //update(i, j, Mat[i-1][j-1]);
                update(i, j, Mat[(i-1)*N + (j-1)]);
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                for(int k = i+1; k <= N; k++){
                    for(int l = j+1; l <= M; l++){
                        //cout<<i<<" "<<j<<" "<<k<<" "<<l<<"\n";
                        //cout<<rectangle(i, j, k, l)<<" ";
                        arr[rectangle(i, j, k, l)]++;
                    }
                }
            }
        }
        int zz = (N*N+N)*(M*M+M)/4;
        double sum = 0;
        for(int i = 0; i <= K; i++){
            sum += (double)i * (double)arr[i]/(double)zz;
            //cout<<arr[i]<<" ";
        }
        cout<<setprecision(16)<<sum<<"\n";
    }
    return 0;
}




