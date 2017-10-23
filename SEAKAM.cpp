#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1e9+7;

ll dp[100007],n;
map < ll,ll > m;
vector < pair < ll,ll > > arr;
vector < vector < ll > > graph;
vector < ll > v;
vector < ll > temp;
bool visited[17];

void pre(){
	dp[0]=1;
	for(ll i=1;i<=100000;i++){
		dp[i]=(dp[i-1]*1LL*i)%MOD;
	}
}

bool dfs(int src, int parent)
{
	int i;
    visited[src] = true;

    for (i = 0; i < graph[src].size(); ++i)
    {
        if (!visited[graph[src][i]])
        {
           if (dfs(graph[src][i], src))
              return true;
        }
        else if (graph[src][i] != parent)
           return true;
    }
    return false;
}

bool checkcycle(int count){
	int i;
	for(i=1;i<count;i++)
        visited[i]=false;
	for (i = 1; i < count; i++)
        if (!visited[i])
          return(dfs(i, -1));

    return false;
}

ll possibilities(vector< ll > v){
	ll i,j,x,y;
	m.clear();
	for(i=0;i<v.size()-1;i++){
		for(j=i+1;j<v.size();j++){
			if(arr[v[i]].first==arr[v[j]].first || arr[v[i]].second==arr[v[j]].second || (v[i]%2==0 && v[j]==v[i]+1)){
				return 0;
			}

		}
	}
	temp.clear();
	ll grps=v.size();
	for(i=0;i<v.size();i++){
		x=arr[v[i]].first;y=arr[v[i]].second;
		for(j=0;j<temp.size();j++){
			if(temp[j]==x){
				grps--;x=-1;
			}
			if(temp[j]==y){
				grps--;y=-1;
			}
		}
		if(x!=-1){
			temp.push_back(x);
		}
		if(y!=-1){
			temp.push_back(y);
		}
	}

	graph.clear();

	ll cnt=1;
	graph.resize(25);
	for(i=0;i<v.size();i++){
		x=arr[v[i]].first;y=arr[v[i]].second;
		if(m[x]==0){
			m[x]=cnt++;
		}
		x=m[x];
		if(m[y]==0){
			m[y]=cnt++;
		}
		y=m[y];
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	if(checkcycle(cnt))return 0;
	ll rem=n-temp.size();
	x=dp[grps+rem];
	return x;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
	ll t,m,i,x,y,ans,j,k,ii,jj,kk,iii,dup;
	cin>>t;
	while(t--){
		arr.clear();
		cin>>n>>m;
		dup=0;
		arr.clear();

		for(i=0;i<m;i++){
			bool fl=false;
			cin>>x>>y;
			if(x==y){
				dup++;fl=true;
			}
			for(j=0;j<arr.size();j++){
				if (arr[j].first==x && arr[j].second==y){
					dup++;
					fl=true;
				}
			}
			if(!fl){
				arr.push_back(make_pair(x,y));
				arr.push_back(make_pair(y,x));
			}
		}

		m=m-dup;
		ans=dp[n];
		if(m==1){
			ans=(ans-(2*1LL*dp[n-1])%MOD+MOD)%MOD;
		}
		if(m==2){
			ans=(ans-(2*m*1LL*dp[n-1])%MOD+MOD)%MOD;
			v.clear();
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					v.push_back(i);
					v.push_back(j);
					ans=(ans+possibilities(v))%MOD;

					v.clear();
				}
			}
		}
		if(m==3){
			ans=(ans-(2*m*1LL*dp[n-1])%MOD+MOD)%MOD;
			v.clear();
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					v.push_back(i);
					v.push_back(j);
					ans=(ans+possibilities(v))%MOD;
					v.clear();
				}
			}
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						v.push_back(i);
						v.push_back(j);
						v.push_back(k);
						ans=(ans-possibilities(v)+MOD)%MOD;
						v.clear();
					}
				}
			}
		}

		if(m==4){
			ans=(ans-(2*m*1LL*dp[n-1])%MOD+MOD)%MOD;
			v.clear();
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					v.push_back(i);
					v.push_back(j);
					ans=(ans+possibilities(v))%MOD;

					v.clear();
				}
			}
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						v.push_back(i);
						v.push_back(j);
						v.push_back(k);

						ans=(ans-possibilities(v)+MOD)%MOD;
						v.clear();
					}
				}
			}

			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						for(ii=k+1;ii<2*m;ii++){
							v.push_back(i);
							v.push_back(j);
							v.push_back(k);
							v.push_back(ii);

							ans=(ans+possibilities(v))%MOD;
							v.clear();
						}
					}
				}
			}
		}

		if(m==5){
			ans=(ans-(2*m*1LL*dp[n-1])%MOD+MOD)%MOD;
			v.clear();
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					v.push_back(i);
					v.push_back(j);
					ans=(ans+possibilities(v))%MOD;
					v.clear();
				}
			}
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						v.push_back(i);
						v.push_back(j);
						v.push_back(k);
						ans=(ans-possibilities(v)+MOD)%MOD;
						v.clear();
					}
				}
			}

			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						for(ii=k+1;ii<2*m;ii++){
							v.push_back(i);
							v.push_back(j);
							v.push_back(k);
							v.push_back(ii);
							ans=(ans+possibilities(v))%MOD;
							v.clear();
						}
					}
				}
			}
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						for(ii=k+1;ii<2*m;ii++)
							for(jj=ii+1;jj<2*m;jj++){
							v.push_back(i);
							v.push_back(j);
							v.push_back(k);
							v.push_back(ii);
							v.push_back(jj);
							ans=(ans-possibilities(v)+MOD)%MOD;
							v.clear();
						}
					}
				}
			}
		}
		if(m==6){
			ans=(ans-(2*m*1LL*dp[n-1])%MOD+MOD)%MOD;
			v.clear();
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					v.push_back(i);
					v.push_back(j);
					ans=(ans+possibilities(v))%MOD;
					v.clear();
				}
			}
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						v.push_back(i);
						v.push_back(j);
						v.push_back(k);
						ans=(ans-possibilities(v)+MOD)%MOD;
						v.clear();
					}
				}
			}

			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						for(ii=k+1;ii<2*m;ii++){
							v.push_back(i);
							v.push_back(j);
							v.push_back(k);
							v.push_back(ii);
							ans=(ans+possibilities(v))%MOD;
							v.clear();
						}
					}
				}
			}
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						for(ii=k+1;ii<2*m;ii++)
							for(jj=ii+1;jj<2*m;jj++){
							v.push_back(i);
							v.push_back(j);
							v.push_back(k);
							v.push_back(ii);
							v.push_back(jj);
							ans=(ans-possibilities(v)+MOD)%MOD;
							v.clear();
						}
					}
				}
			}
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						for(ii=k+1;ii<2*m;ii++)
							for(jj=ii+1;jj<2*m;jj++)
								for(kk=jj+1;kk<2*m;kk++){
							v.push_back(i);
							v.push_back(j);
							v.push_back(k);
							v.push_back(ii);
							v.push_back(jj);
							v.push_back(kk);
							ans=(ans+possibilities(v))%MOD;
							v.clear();
						}
					}
				}
			}
		}

		if(m==7){
			ans=(ans-(2*m*1LL*dp[n-1])%MOD+MOD)%MOD;
			v.clear();
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					v.push_back(i);
					v.push_back(j);
					ans=(ans+possibilities(v))%MOD;
					v.clear();
				}
			}

			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						v.push_back(i);
						v.push_back(j);
						v.push_back(k);
						ans=(ans-possibilities(v)+MOD)%MOD;
						//cout<<ans<<endl;
						v.clear();
					}
				}
			}

			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						for(ii=k+1;ii<2*m;ii++){
							v.push_back(i);
							v.push_back(j);
							v.push_back(k);
							v.push_back(ii);
							ans=(ans+possibilities(v))%MOD;
							v.clear();
						}
					}
				}
			}
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						for(ii=k+1;ii<2*m;ii++)
							for(jj=ii+1;jj<2*m;jj++){
							v.push_back(i);
							v.push_back(j);
							v.push_back(k);
							v.push_back(ii);
							v.push_back(jj);
							//if(possibilities(v)>0)cout<<i<<' '<<j<<' '<<k<<' '<<ii<<' '<<jj<<' '<<possibilities(v)<<endl;
							ans=(ans-possibilities(v)+MOD)%MOD;
							v.clear();
						}
					}
				}
			}
			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						for(ii=k+1;ii<2*m;ii++)
							for(jj=ii+1;jj<2*m;jj++)
								for(kk=jj+1;kk<2*m;kk++){
							v.push_back(i);
							v.push_back(j);
							v.push_back(k);
							v.push_back(ii);
							v.push_back(jj);
							v.push_back(kk);
							ans=(ans+possibilities(v))%MOD;
							v.clear();
						}
					}
				}
			}

			for(i=0;i<2*m-1;i++){
				for(j=i+1;j<2*m;j++){
					for(k=j+1;k<2*m;k++){
						for(ii=k+1;ii<2*m;ii++)
							for(jj=ii+1;jj<2*m;jj++)
								for(kk=jj+1;kk<2*m;kk++)
									for(iii=kk+1;iii<2*m;iii++){
							v.push_back(i);
							v.push_back(j);
							v.push_back(k);
							v.push_back(ii);
							v.push_back(jj);
							v.push_back(kk);
							v.push_back(iii);
							ans=(ans-possibilities(v)+MOD)%MOD;
							v.clear();
						}
					}
				}
			}
		}

		cout<<ans<<"\n";
	}

	return 0;
}
