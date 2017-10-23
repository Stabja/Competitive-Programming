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

int main(int argc, char const *argv[])
{
	string s;
	LL a, t;
	cin>>s>>t;

	for(int i = 0; i < t; i++){
	    int f = 0;
	    for(int j = 1; j < s.size(); j++){
	        if(s[j] > s[j-1]){
	            f = 1;
	            swap(s[j-1], s[j]);
	            break;
	        }
	    }
	    if(f == 0){
	        break;
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
