#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int l = str.length();
        if(l%2 == 0){                  //If string length is Even
            string str1 = str.substr(0, l/2);
            string str2 = str.substr(l/2, l/2);
            if(str1.compare(str2) == 0)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else{                          //If string length is odd
            int x = l/2;
            int flag = 0;
            if(str[0] == str[x]){       //if X lies on right side
                int cnt = 0;
                int i = 0;
                int j = x;
                flag = 1;
                while(i < x){
                    if(str[i] != str[j]){
                        if(cnt == 1){
                            flag = 0;
                            break;
                        }
                        cnt++;
                        j++;
                    }
                    else{
                       i++;
                       j++;
                    }
                }
            }
            if(str[0] == str[x+1]){    //If X lies on left or center
                int cnt = 0;
                int i = 0;
                int j = x+1;
                flag = 1;
                while(i < x+1){
                    if(str[i] != str[j]){
                        if(cnt == 1){
                            flag = 0;
                            break;
                        }
                        cnt++;
                        i++;
                    }
                    else{
                        i++;
                        j++;
                    }
                }
            }
            if(str[1] == str[x+1]){           //If X is the beginning element
                int i = 1;
                int j = x+1;
                flag = 1;
                while(j < l){
                    if(str[i] != str[j]){
                        flag = 0;
                        break;
                    }
                    else{
                        i++;
                        j++;
                    }
                }
            }
            if(flag == 1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
