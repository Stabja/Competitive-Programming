#include<bits/stdc++.h>
#define vonLoop(m , i)(typeof(m) i = m.begin(); i != m.end(); i++)
using namespace std;

map<string, bool> swaps;
vector<string> permutes;


void recursion(map<string, bool> s){

}

int main(){
    int t;
    cin>>t;
    string str;
    while(t--){
        cin>>str;
        string temp = str;
        swaps[str] = true;
        do{
            /*for(int i = 0; i < str.length(); i++){
                cout<<str[i]<<" ";
            }
            cout<<"\n";*/
            swaps[temp] = false;
        }while(next_permutation(temp.begin(), temp.end()));
        swaps[str] = true;
        int cnt = 0;
        int cnt2 = 0;
        for(map<string, bool>::iterator it = swaps.begin(); it != swaps.end(); ++it){
            string str2 = (*it).first;
            cnt = 0;
            cnt2 = cnt;
            for(int i = 0; i < str2.length(); i++){
                for(int j = i+1; j < str2.length(); j++){
                    char c = str2[i];
                    str2[i] = str2[j];
                    str2[j] = c;
                    //permutes.push_back(str2);
                    if(swaps[str2] == false){
                        swaps[str2] = true;
                        cnt2++;
                    }
                    str2 = (*it).first;
                }
            }
        }
        /*vonLoop(swaps , i){
            cout<<i->first<<"\n";
        }*/
        for(map<string, bool>::iterator it = swaps.begin(); it != swaps.end(); ++it){
            //if((*it).second == true){
                cout<<(*it).first<<" "<<(*it).second<<"\n";
            //}
        }
    }
    return 0;
}
