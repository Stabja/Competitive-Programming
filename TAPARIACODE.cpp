#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool visit[10000005];
vector<vector<int> > v;
int cnt=0;

void dfs(int src){
	visit[src]=true;
	for(int i=0;i<v[src].size();i++){
		if(!visit[v[src][i]]){
			dfs(v[src][i]);
		}
	}
}
int main(){
	int i,n,x,y;
	cin>>n>>x;
	v.resize(n+1);
	for(i=1;i<=n;i++){
		scanf("%d",&y);
		v[y].push_back(i);
		v[i].push_back(y);
	}
	for(i=1;i<=n;i++){
		if(!visit[i]){
			dfs(i);
			cnt++;
		}
	}
	cout<<cnt*1LL*x<<endl;
}
