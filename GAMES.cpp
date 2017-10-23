#include<bits/stdc++.h>
#include<string>
using namespace std;

#define MAXX 1000000

int Rtimes[1000001];
int Ctimes[1000001];
int Rtemp[1000001];
int Ctemp[1000001];
int Rindex[1000001];
int Cindex[1000001];

int Mat[1000003];

void display(int m, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<Mat[i*m+j];
        }
        cout<<"\n";
    }
    cout<<"\n\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout<<Mat[i+j*n];
        }
        cout<<"\n";
    }
}

void displayRes(){
    for(int i = 1; i < 10; i++){
        cout<<Rtimes[i]<<" ";
    }
    cout<<"\n";
    for(int i = 1; i < 10; i++){
        cout<<Rindex[i]<<" ";
    }
    cout<<"\n";
    for(int i = 1; i < 10; i++){
        cout<<Ctimes[i]<<" ";
    }
    cout<<"\n";
    for(int i = 1; i < 10; i++){
        cout<<Cindex[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n, m;
        cin>>n>>m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>Mat[i*m+j];
            }
        }
        //display(m, n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                Rtemp[Mat[i*m+j]]++;
            }
            for(int k = 1; k <= MAXX; k++){
                if(Rtemp[k] > Rtimes[k]){
                    Rtimes[k] = Rtemp[k];
                    Rindex[k] = i;
                }
            }
            memset(Rtemp, 0, sizeof Rtemp);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                Ctemp[Mat[i+j*n]]++;
            }
            for(int k = 1; k <= MAXX; k++){
                if(Ctemp[k] > Ctimes[k]){
                    Ctimes[k] = Ctemp[k];
                    Cindex[k] = i;
                }
            }
            memset(Ctemp, 0, sizeof Ctemp);
        }
        //displayRes();
        int maxxx = 0;
        for(int i = 1; i <= MAXX; i++){
            int total = Rtimes[i]+Ctimes[i];
            if(Mat[Rindex[i]*m+Cindex[i]] == i)
                total--;
            maxxx = max(maxxx, total);
        }
        cout<<maxxx<<"\n";
    }
    return 0;
}
