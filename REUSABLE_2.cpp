#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    int T;
    map<string, bool> hmap;
    cin>>T;
    while(T--){
       string str;
       cin>>str;
       for(int i = 0; i < str.length()-1; i++){
           string temp = str.substr(i, 2);
           hmap[temp] = true;
       }
       cout<<hmap.size()<<"\n";
       hmap.clear();
    }
    return 0;
}
