#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,n) for(int i=a;i<n;i++)
#define MOD 1000000007
#define LL long long int
#define mp make_pair
#define pb push_back

bool compare(int a, int b){
    return a > b;
}

void findMax(string str, int ){
}

int main(int argc, char const *argv[])
{
	string str;
	LL a, t;
	cin>>str>>t;
	int n = str.length();
	string tmp = str;
	for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(str[i] < str[j]){
                swap(str[i], str[j]);
                if(str.compare(tmp) > 0)
                    tmp = str;
            }
            findMa
        }
	}
	//t -= 1;
	t %= 2;
	if(t && s.size() >= 2){
	    swap(s[s.size()-1], s[s.size()-2]);
	}
	cout<<s;
	return 0;

}
