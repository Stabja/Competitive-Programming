#include<bits/stdc++.h>
using namespace std;

vector<string> permutes;

int main(){
    int t;
    cin>>t;
    string str;
    while(t--){
        cin>>str;
        do{
            /*for(int i = 0; i < str.length(); i++){
                cout<<str[i]<<" ";
            }
            cout<<"\n";*/
            permutes.push_back(str);
        }while(next_permutation(str.begin(), str.end()));
        for(int i = 0; i < permutes.size(); i++){
            cout<<permutes[i]<<"\n";
        }
    }
    return 0;
}
