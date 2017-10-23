#include<bits/stdc++.h>
#include<string>
using namespace std;

int frequency[1000];

int main(){
    string str;
    cin>>str;
    memset(frequency, 0, sizeof frequency);
    for(int i = 0; i < str.length(); i++){
        frequency[(int)str[i]]++;
    }
    int x = (int)'a';
    for(int i = x; i < x+26; i++){
        cout<<frequency[i]<<"\n";
    }
    return 0;
}
