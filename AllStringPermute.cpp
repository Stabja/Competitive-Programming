#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;

vector<string> buff1;
vector<string> buff2;

void AppendAll(string str, char ch){
    int l = str.length();
    string s(1, ch);
    for(int i = 0; i <= l; i++){
        string temp1 = str.substr(0, i);
        string temp2 = str.substr(i, l-i);
        temp1 += s + temp2;
        buff2.push_back(temp1);
        //cout<<temp1<<"\n";
    }
}

int main(){
    string str1("abcd");
    string str2;
    cin>>str2;
    buff1.push_back(string(1, str2[0]));
    for(int j = 1; j < str2.size(); j++){
        for(int i = 0; i < buff1.size(); i++){
            AppendAll(buff1[i], str2[j]);
        }
        buff1.clear();
        for(int i = 0; i < buff2.size(); i++){
            buff1.push_back(buff2[i]);
        }
        if(j != str2.size()-1){
            buff2.clear();
        }
    }
    int k = 0;
    for(int i = 0; i < buff2.size(); i++){
        cout<<buff2[i]<<"\n";
        k++;
    }
    cout<<k;
    return 0;
}
