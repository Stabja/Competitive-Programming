#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000009
#define LL long long int
#define mp make_pair
#define pb push_back

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        if(str.length() == 1){
            cout<<"yes\n";
        }
        else{
            int flag = 0;
            for(int i = 0; i < str.length()-1; i++){
                string temp = str.substr(i, 2);
                if(temp.compare("EC") == 0 || temp.compare("SC") == 0 || temp.compare("SE") == 0){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                cout<<"yes\n";
            }
            else{
                cout<<"no\n";
            }
        }
    }
    return 0;
}
