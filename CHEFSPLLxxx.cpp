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
        else{
            int flag = 0;
            string sub1, sub2;
            if(flag == 0){
                sub1 = str.substr(1, l/2);     //FRONT
                sub2 = str.substr((l/2)+1, l/2);
                if(sub1.compare(sub2) == 0){
                    flag = 1;
                    //cout<<" Front\n";
                }
            }
            if(flag == 0){                        //CENTER
                sub1 = str.substr(0, l/2);
                sub2 = str.substr((l/2)+1, l/2);
                if(sub1.compare(sub2) == 0){
                    flag = 1;
                    //cout<<" Center\n";
                }
            }
            if(flag == 0){                        //LAST
                sub1 = str.substr(0, l/2);
                sub2 = str.substr((l/2), l/2);
                if(sub1.compare(sub2) == 0){
                    flag = 1;
                    //cout<<" Last\n";
                }
            }
            if(flag == 0){
                sub1 = str.substr(0, (l/2)+1);
                sub2 = str.substr((l/2)+1, l/2);
                int i = 0;
                int j = 0;
                int cnt = 0;
                flag = 1;
                while(i <= l/2){
                    if(sub1[i] != sub2[j]){
                        if(cnt == 1){
                            flag = 0;
                            //cout<<" Left\n";
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
            if(flag == 0){
                sub1 = str.substr(0, l/2);
                sub2 = str.substr(l/2, (l/2)+1);
                int i = 0;
                int j = 0;
                int cnt = 0;
                flag = 1;
                while(i < l/2){
                    if(sub1[i] != sub2[j]){
                        if(cnt == 1){
                            flag = 0;
                            //cout<<" Right\n";
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
            if(flag == 1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
