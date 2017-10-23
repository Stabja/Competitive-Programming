#include<bits/stdc++.h>
using namespace std;

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

struct node{
    int x;
    int y;
    int z;
};

bool visited[2001];
bool connected[2001];
int pptr[2001];
vector<node> vertex[2002];
int longest;
stack<int> path;

int dfs(int s){
    int sum = 0;
    visited[s] = true;
    int flag = 0;
    int dist = 0;
    path.push(vertex[s][0].x);
    for(int i = 0; i < vertex[s].size(); i++){
        if(!visited[vertex[s][i].x] && vertex[s][i].z == 1){
            flag = 1;
            visited[vertex[s][i].x] = true;
            //dist = max(dist, vertex[s][i].y + dfs(vertex[s][i].x));
            int x = vertex[s][i].y + dfs(vertex[s][i].x);
            if(x > dist){
                dist = x;
                path.pop();
                path.push(vertex[s][i].x);
            }
        }
    }
    return dist;
}

void fakeDfs(int s){
    connected[s] = true;
    for(int i = 0; i < vertex[s].size(); i++){
        if(!connected[vertex[s][i].x] && vertex[s][i].z == 1){
            connected[vertex[s][i].x] = true;
            fakeDfs(vertex[s][i].x);
        }
    }
}

int main(){
    int t;
    t = read();
    while(t--){
        int n;
        n = read();
        int u, v, w;
        pptr[0] = 0;
        pptr[1] = 0;
        for(int i = 0; i < n-1; i++){
            u = read();
            v = read();
            w = read();
            node temp1, temp2;
            temp1.x = v;
            temp1.y = w;
            temp1.z = 1;
            temp2.x = u;
            temp2.y = w;
            temp2.z = 1;
            pptr[max(u, v)] = min(u, v);
            vertex[u].push_back(temp1);
            vertex[v].push_back(temp2);
        }
        int ans = 1000000000;
        for(int i = 1; i <= n; i++){
            int k1 = 0, k2 = 0;
            if(i != 1)
            {
                for(k1 = 0; k1 < vertex[i].size(); k1++){
                    if(vertex[i][k1].x == pptr[i]){
                        vertex[i][k1].z = 0;
                        break;
                    }
                }
                for(k2 = 0; k2 < vertex[pptr[i]].size(); k2++){
                    if(vertex[pptr[i]][k2].x == i){
                        vertex[pptr[i]][k2].z = 0;
                        break;
                    }
                }
            }
            memset(connected, false, sizeof(connected));
            fakeDfs(i);
            for(int j = 1; j <= n; j++){
                if(connected[j]){
                    visited[j] = true;
                    ans = min(ans, dfs(j));
                    //cout<<longest<<" ";
                    memset(visited, false, sizeof(visited));
                }
            }
            memset(visited, false, sizeof(visited));
            /*for(int j = 0; j < vertex[i].size(); j++){
                if(connected[vertex[i][j].x]){
                    visited[vertex[i][j].x] = true;
                    ans = min(ans, dfs(vertex[i][j].x));
                    memset(visited, false, sizeof(visited));
                }
            }*/
            cout<<ans<<"\n";
            ans = 1000000000;
            if(i != 1){
                vertex[i][k1].z = 1;
                vertex[pptr[i]][k2].z = 1;
            }
        }
        for(int i = 0; i < 2001; i++){
            vertex[i].clear();
        }
    }
    return 0;
}
