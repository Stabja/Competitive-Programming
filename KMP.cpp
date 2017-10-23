#include<bits/stdc++.h>
#include<algorithm>
#include<string.h>
using namespace std;

void PreProcess(string pat, int M, int *suff);

void applyKMP(string txt, string pat){
    int M = txt.length();
    int N = pat.length();

    int *suff = (int*)malloc(sizeof(int)*N);
    PreProcess(pat, N, suff);

    int i = 0;
    int j = 0;
    bool flag = false;

    while(i < M){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        if(j == N){
            cout<<"Pattern found at "<<(i-j)<<"\n";
            j = suff[j-1];
            flag = true;
        }
        else if(i < M && txt[i] != pat[j]){
            if(j != 0)
                j = suff[j-1];
            else
                i++;
        }
    }
    if(!flag){
        cout<<"Pattern not found\n";
    }
    free(suff);
}

void PreProcess(string pat, int M, int *suff){
    int j = 0;
    int i = 1;
    suff[0] = 0;
    while(i < M){
        if(pat[i] == pat[j]){
            j++;
            suff[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j = suff[j-1];
            }
            else{
                suff[i] = 0;
                i++;
            }
        }
    }
    /*for(int i = 0; i < pat.length(); i++){
        cout<<suff[i]<<" ";
    }*/
}

int main(){
    string txt;
    string pat;
    cin>>txt>>pat;
    applyKMP(txt, pat);
    return 0;
}
