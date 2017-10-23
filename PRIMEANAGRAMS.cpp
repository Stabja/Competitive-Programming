#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000005

bool prime[MAXX];
int ans[3];
vector<int> xx;

void sieve(){
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int p=2; p*p<=1000000; p++){
        if (prime[p] == true){
            for (int i=p*2; i<=1000000; i += p)
                prime[i] = false;
        }
    }
}

int main(){
    sieve();
    string str;
    cin>>str;
    int l = str.length();
    long long int pro = 1;
    long long int minPro = 1000000000;
    sort(str.begin(), str.end());
    do{
        if(str[0] == '0')
            continue;
        for(int i = 1; i < l-1; i++){
            for(int j = i+1; j < l; j++){
                string s1 = str.substr(0, i);
                string s2 = str.substr(i, j-i);
                string s3 = str.substr(j, l-j);
                if(s1[0] == '0' || s2[0] == '0' || s3[0] == '0')
                    continue;
                int v1 = atoi(s1.c_str());
                int v2 = atoi(s2.c_str());
                int v3 = atoi(s3.c_str());
                if(prime[v1] && prime[v2] && prime[v3]){
                    pro = 1LL*v1*v2*v3;
                    if(pro < minPro){
                        minPro = pro;
                        ans[0] = v1;
                        ans[1] = v2;
                        ans[2] = v3;
                    }
                }
            }
        }
    }while(next_permutation(str.begin(), str.end()));
    sort(ans, ans+3);
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
    xx.push_back(ans[0]);
    xx.push_back(ans[1]);
    xx.push_back(ans[2]);
    return 0;
}
