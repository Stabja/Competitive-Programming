#include<bits/stdc++.h>
#include<string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define MOD 1000000009
#define LL long long int
#define mp make_pair
#define pb push_back

int main(){
    int t;
    string tt;
    char buffer[256];
    fgets(buffer, 256, stdin);
    t = atoi(buffer);
    while(t--){
        string str;
        getline(cin, str);
        int cnt = 0;            //No of spaces
        for(int i = 0; i < str.length(); i++){
            if(str[i] == ' '){
                cnt++;
            }
        }
        if(cnt == 0){
            str[0] = toupper(str[0]);
            for(int i = 1; i < str.length(); i++){
                str[i] = tolower(str[i]);
            }
            cout<<str<<"\n";
        }
        else{
            string target = "";
            int cnt2 = 0;
            target += toupper(str[0]);
            target += ". ";
            for(int i = 0; i < str.length(); i++){
                if(str[i] == ' ' && cnt2 < cnt-1){
                    cnt2++;
                    target += toupper(str[i+1]);
                    target += ". ";
                }
                else if(str[i] == ' ' && cnt2 == cnt-1){
                    cnt2++;
                }
                if(cnt2 == cnt){
                    target += toupper(str[i+1]);
                    for(int j = i+2; j < str.length(); j++){
                        target += tolower(str[j]);
                    }
                    break;
                }
            }
            cout<<target<<"\n";
        }
    }
    return 0;
}
