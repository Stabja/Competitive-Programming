#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000009
#define LL long long int
#define mp make_pair
#define pb push_back

int arr[1005];
vector<int> indx[100005];

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++){
        indx[arr[i]].push_back(i);   //Hashing
    }
    int ans = INT_MAX;
    for(int i = 1; i < 100005; i++){
        if(indx[i].size() > 1){
            for(int j = 0; j < indx[i].size()-1; j++){
                ans = min(ans, indx[i][j+1] - indx[i][j]);
            }
        }
    }
    if(ans == INT_MAX)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
