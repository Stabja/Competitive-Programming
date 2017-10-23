#include<bits/stdc++.h>
using namespace std;
std::vector<string> V;
int X,Y,Z;
double dp[23][407];
double power(int ch,double x){
    double y = 1;
    while(ch){
        y *= x;
        ch--;
    }
    return y;
}
double solve(int chances,int sum,int maximum,int index){
    if(chances == 0){
        if(sum <= 0)return 1;
        return 0;
    }
    if(sum <= 0){
        return dp[index][sum] = power(chances,maximum);
    }
    if(dp[index][sum] >= 0){
        return dp[index][sum];
    }
    double ans = 0;
    for(int i = 1;i <= maximum;i++){
        ans += solve(chances-1,sum-i,maximum,index+1);
    }
    return dp[index][sum] = ans;
}
void parse_string(string s){
	Y = 0;
	int i;
	for(i = 0;i < s.length();i++){
		if(s[i] == 'd')break;
		else{
			Y = Y*10 + (s[i]-'0');
		}
	}
	i++;
	int fl = 0;
	X = 0;
	for(;i < s.length();i++){
		if(s[i] == '+'){
			fl = -1;break;
		}
		else if(s[i] == '-'){
			fl = 1;break;
		}
		else{
			X = X*10 + (s[i] - '0');
		}
	}
	i++;
	if(fl != 0){
		int z = 0;
		for(;i < s.length();i++){
			z = z*10 + (s[i]-'0');
		}
		Z += (z*fl);
	}
}
int main(){
	int t,h,s;
	string st;
	cin>>t;
	for(int tc = 1;tc <= t;tc++){
		//cerr<<tc<<endl;
		cin>>h>>s;
		V.clear();
		for(int i = 0;i < s;i++){
			cin>>st;
			V.push_back(st);
		}

		double ans = 0;
		for(int i = 0;i < V.size();i++){
			Z = h;
			parse_string(V[i]);
			//cerr<<X<<' '<<Y<<' '<<Z<<endl;
			if(Z > X*Y)continue;
			else if(Z <= 0){
				ans = 1;break;
			}
			memset(dp,-1,sizeof(dp));
		    double denominator = 1.0;
		    for(int i = 0;i < Y;i++){
		        denominator *= X;
		    }
		    //cerr<<"Done\n";
		    double numerator = solve(Y,Z,X,0);
		    //cerr<<numerator<<' '<<denominator<<endl;
		    ans = max(ans,numerator/denominator);
		    //cout<<numerator/denominator<<endl;
		}
		printf("Case #%d: %lf\n",tc,ans);
		//cout<<"Case #"<<tc<<": "<<ans<<"\n";
	}
	return 0;
}