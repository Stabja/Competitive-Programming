#include<bits/stdc++.h>
using namespace std;
double ar[102];
int main()
{
	//freopen("lazy_loading.txt","r",stdin);
	//freopen("face.txt","w",stdout);
	int t,n;
	cin>>t;
	for(int h=1;h<=t;h++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>ar[i];
		}
		sort(&ar[1],&ar[n+1]);
		int higher=n;
		int ctr=0;
		int lower=1;
		while(true)
		  {
		double cur=ar[higher];
		double needed=ceil(50.0/cur);
		if(needed==1)
		{
			ctr++;
			higher--;
			if(higher<lower)
			{
				break;
			}
		}else
		{
			higher--;
			lower=lower+needed-1;
			ctr++;
			if(higher==(lower-1))
			{
				break;
			}else if(higher<lower)
			{
				ctr--;
				break;
			}
		}
	      }
	      cout<<"Case #"<<h<<":"<<" "<<ctr<<"\n";
	}
}
