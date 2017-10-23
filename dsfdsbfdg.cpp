#include<bits/stdc++.h>
using namespace std;

#define MAXX 1000000007
#define LL long long int
#define pb push_back
#define mp make_pair

list<int> ll;

int main(){
    int n;
    cin>>n;
    int val;
    int num = 0;
    for(int i = 0; i < n; i++){
        cin>>val;
        ll.push_back(val);
        num += val*pow(10, n-i-1);
    }
    int num2 = num+1;
    stringstream ss, ss2;
    ss << num;
    ss2 << num2;
    string str = ss.str();
    string str2 = ss2.str();
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(str[i] != '9'){
            flag = 1;
            break;
        }
    }
    int i = 0;
    for(list<int>::iterator it = ll.begin(); it != ll.end(); ++it){
        (*it) = str2[i++] - '0';
    }
    if(flag == 0){
        ll.push_back(0);
    }
    for(list<int>::iterator it = ll.begin(); it != ll.end(); ++it){
        cout<<(*it)<<" ";
    }
    return 0;
}
