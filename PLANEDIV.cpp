#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define MAXX 100000
map<double, int> groups;

struct line{
    double m;
    double c;
};

bool compare(line a , line b){
    if(a.m != b.m){
        return a.m < b.m;
    }else{
        return a.c < b.c;
    }
}

int main(){
    int T, N;
    double a, b, c;
    cin>>T;
    while(T--){
        cin>>N;
        struct line *lines = (struct line*)malloc(sizeof(struct line)*N);
        for(int i = 0; i < N; i++){
            cin>>a>>b>>c;
            if(b != 0){
                lines[i].m = (double)(-a)/(double)b;
                lines[i].c = (double)(-c)/(double)b;
            }else{
                lines[i].m = MAXX;
                lines[i].c = (double)(-c)/(double)a;
            }
        }
        sort(lines, lines+N, compare);
        groups[lines[0].m]++;
        for(int i = 1; i < N; i++){
            if(lines[i].m == lines[i-1].m && lines[i].c == lines[i-1].c)
                continue;
            groups[lines[i].m]++;
        }
        int largest = 0;
        for(map<double, int>::iterator it = groups.begin(); it != groups.end(); ++it){
            if((*it).second > largest){
                largest = (*it).second;
            }
        }
        cout<<largest<<"\n";
        groups.clear();
        free((void*)lines);
    }
    return 0;
}
