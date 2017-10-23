#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,w;
	cin>>t;
	for(int tc = 1;tc <= t;tc++){
		cin>>n;
		//if(tc == 63)cerr<<n<<endl;
		std::vector<int> v;
		v.clear();
		int ans = 0,ctr = 0;
		for(int i = 0;i < n;i++){
			cin>>w;
			// if(tc == 63){
			// 	cerr<<w<<endl;
			// }
			if(w >= 50)ans++;
			else{
				v.push_back(w);ctr++;
			}
		}
		sort(v.begin(),v.end());
		int start,end;
		start = 0;end = ctr-1;
		while(start < end){
			int x = ceil(50.0/v[end]);
			//cerr<<x<<endl;
			if(end-start+1 >= x){
				//cerr<<start<<' '<<end<<endl;
				ans++;
			}
			end -= 1;
			start += (x-1);
			//cerr<<start<<' '<<end<<endl;
		}
		cout<<"Case #"<<tc<<": "<<ans<<"\n";
	}
	return 0;
}