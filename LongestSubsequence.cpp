#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string s1, s2;
    char ch1[100], ch2[100];
    cin>>s1;
    cin>>s2;
    strcpy(ch1, s1.c_str());
    strcpy(ch2, s2.c_str());
    for(int i = 0; i < s1.size() ; i++){
        cout<<ch1[i];
    }
    cout<<"\n";
    for(int i = 0; i < s1.size(); i++){
        cout<<ch2[i];
    }

    return 0;
}
