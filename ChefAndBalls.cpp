#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int arr[100][100];
int row[100][100];
int col[100][100];

void debug(int r, int c){
    cout<<"\n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout<<row[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout<<col[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int r, c;
        cin>>r>>c;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin>>arr[i][j];
            }
        }
        for(int i = 0; i < r; i++){
            row[i][0] = arr[i][0];
        }
        for(int i = 0; i < c; i++){
            col[0][i] = arr[0][i];
        }
        for(int i = 0; i < r; i++){
            for(int j = 1; j < c; j++){
                if(arr[i][j] == 0){
                    row[i][j] = 0;
                }
                else{
                    row[i][j] = row[i][j-1]+1;
                }
            }
        }
        for(int i = 0; i < c; i++){
            for(int j = 1; j < r; j++){
                if(arr[j][i] == 0){
                    col[j][i] = 0;
                }
                else{
                    col[j][i] = col[j-1][i]+1;
                }
            }
        }
        debug(r, c);
        int maxx = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                maxx = max(maxx, row[i][j]*col[i][j]);
            }
        }
        cout<<maxx;
    }
    return 0;
}
