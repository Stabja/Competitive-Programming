#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;

#define pb push_back

int *T[1000][1000];

struct Point{
    int x, y;
};

vector<Point> bish;
int cnt;

int main(){
    int N;
    cin>>N;
    int x, y;
    for(int i = 0; i < N; i++){
        cin>>x>>y;
        Point p;
        p.x = x;
        p.y = y;
        bish.pb(p);
    }
    /*for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(abs(bish[i].x - bish[j].x) == abs(bish[i].y - bish[j].y))
                cnt++;
        }
    }*/
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            *T[i][j] = 0;
        }
    }
    for(int i = 0; i < N; i++){
        int m = bish[i].x;
        int n = bish[y].y;
        for(int j = 0; j < 1000; j++){
            if(max(m+j, n+j) < 1000)
                *T[m+j][n+j] = 1;
            if(max(m+j, n-j) < 1000 && min(m+j, n-j) >= 0)
                *T[m+j][n-j] = 1;
            if(max(m-j, n+j) < 1000 && min(m-j, n+j) >= 0)
                *T[m-j][n+j] = 1;
            if(min(m-j, n-j) >= 0)
                *T[m-j][n-j] = 1;
        }
    }
    for(int i = 0; i < N; i++){
        int m = bish[i].x;
        int n = bish[y].y;
        if(*T[m][n] == 1)
            cnt++;
    }
    cout<<cnt;
    return 0;
}
