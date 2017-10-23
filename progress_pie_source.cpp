#include<bits/stdc++.h>
using namespace std;
const double PI = 2*acos(0.0);
int main(){
	int t,X,Y,x2,y2,x1,y1;
	double p;
	cin>>t;
	for(int tc = 1;tc <= t;tc++){
		cin>>p>>X>>Y;
		p *= 3.6;
		double theta;
		if(p == 0){
			cout<<"Case #"<<tc<<": "<<"white\n";
			continue;
		}
		//cerr<<X<<endl;
		if(X >= 50){
			x1 = 0;y1 = 50;
			x2 = X - 50;y2 = Y- 50;
			double dist = sqrt(x2*x2+y2*y2);
			if(dist > 50){
				cout<<"Case #"<<tc<<": "<<"white\n";
				continue;
			}
			//cerr<<"In\n";
			double Z = x1*x2 + y1*y2;
			Z /= sqrt(x1*x1+y1*y1);
			Z /= dist;
			//cerr<<Z<<endl;
			theta = acos(Z);
			theta /= PI;
			theta *= 180.0;
			//cerr<<theta<<endl;
			if(theta <= p){
				cout<<"Case #"<<tc<<": "<<"black\n";
				continue;
			}
			else{
				cout<<"Case #"<<tc<<": "<<"white\n";
				continue;
			}
		}
		else{
			//cerr<<p<<" In\n";
			x1 = 0;y1 = -50;
			x2 = X - 50;y2 = Y- 50;
			double dist = sqrt(x2*x2+y2*y2);
			if(dist > 50){
				cout<<"Case #"<<tc<<": "<<"white\n";
				continue;
			}
			double Z = x1*x2 + y1*y2;
			Z /= sqrt(x1*x1+y1*y1);
			Z /= dist;
			theta = acos(Z);
			theta /= PI;
			theta *= 180.0;
			theta += 180;
			//cerr<<(theta<=p)<<endl;
			if(theta <= p){
				cout<<"Case #"<<tc<<": "<<"black\n";
				continue;
			}
			else{
				cout<<"Case #"<<tc<<": "<<"white\n";
				continue;
			}
		}
	}
	return 0;
}