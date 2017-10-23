#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define MAXX 1000000007

#ifndef ONLINE_JUDGE
	#define gc getchar
#else
	#define gc getchar_unlocked
#endif

inline int read(){
	int res = 0,sign = 1;
	char c = gc();
	while(!(c>='0' && c<='9')){
		if(c=='-')
		sign = -1;
		c = gc();
	}
	while(c>='0' && c<='9'){
		res = (res<<3)+(res<<1)+c-'0';
		c = gc();
	}
	return res*sign;
}

LL recurse(int n, char *ch, string str, int k, int ham, int a){
    if(k == n){
        return 1;
    }
    LL cnt = 0;
    int d = k/2;
    int flag = 0;

    if(ham == 0){
        str.push_back(ch[k]);
        for(int i = 1; i <= d; i++){
            if(str[k] == str[k-i] && str[k-i] == str[k-2*i]){
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cnt = (cnt%MAXX + recurse(n, ch, str, k+1, ham, a)%MAXX)%MAXX;
    }
    else{
        for(char j = 'a'; j < (char)((int)'a' + a); j++){
            str.push_back(j);
            for(int i = 1; i <= d; i++){
                if(str[k] == str[k-i] && str[k-i] == str[k-2*i]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                if(ch[k] != str[k])
                    cnt = (cnt%MAXX + recurse(n, ch, str, k+1, ham-1, a)%MAXX)%MAXX;
                else
                    cnt = (cnt%MAXX + recurse(n, ch, str, k+1, ham, a)%MAXX)%MAXX;
            }
            flag = 0;
            str.erase(str.begin()+(str.size()-1));
        }
    }
    return cnt;
}

int main()
{
    int t;
    t = read();
    while(t--){
        int a, k;
        char ch[54];
        string str;
        a = read();
        k = read();
        scanf("%s", &ch);
        int n = strlen(ch);
        LL cntt = recurse(n, ch, str, 0, k, a);
        cout<<cntt<<"\n";
    }
    return 0;
}
