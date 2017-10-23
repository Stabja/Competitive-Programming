#include<bits/stdc++.h>
using namespace std;
bool dist(double x,double y)
{
	double z=sqrt( ( (x-50.0)*(x-50.0) ) + ( (y-50.0)*(y-50.0) ));
	//cout<<z<<"\n";
	if(z>50.0)
	{
		return false;
	}else
	{
		return true;
	}
}
int main()
{
	freopen("progress_pie.txt","r",stdin);
	freopen("face.txt","w",stdout);
	int t;
	cin>>t;
	double p,x,y,angle;
	double an1,an2,an3;
	for(int h=1;h<=t;h++)
	{
		cin>>p>>x>>y;
		angle=(360.0/100.0)*p;
		if(dist(x,y)==false)
		{
			cout<<"Case #"<<h<<":"<<" white\n";
			continue;
		}
	    if(x==50 && y>=50)
	    {
	    	if(p>0)
	    	{
	    		cout<<"Case #"<<h<<":"<<" black\n";
			}else
			{
				cout<<"Case #"<<h<<":"<<" white\n";
			}
		}else if(x>=50 && y==50)
		{
			if(angle>=90.0)
	    	{
	    		cout<<"Case #"<<h<<":"<<" black\n";
			}else
			{
				cout<<"Case #"<<h<<":"<<" white\n";
			}
		}else if(x>=50 && y>=50)
		{
			an1=(y-50.0)/(x-50.0);
			an2=atan(an1);
			an2=((180.0*7.0)/22.0)*an2;
			an3=90.0-an2;
			if(an3<=angle)
			{
				cout<<"Case #"<<h<<":"<<" black\n";
			}else
			{
				cout<<"Case #"<<h<<":"<<" white\n";
			}
		}else if(x==50 && y<=50)
		{
			if(angle>=180.0)
	    	{
	    		cout<<"Case #"<<h<<":"<<" black\n";
			}else
			{
				cout<<"Case #"<<h<<":"<<" white\n";
			}
		}else if(x<=50 && y==50)
		{
			if(angle>=270.0)
	    	{
	    		cout<<"Case #"<<h<<":"<<" black\n";
			}else
			{
				cout<<"Case #"<<h<<":"<<" white\n";
			}
		}else if(x>=50 && y<=50)
		{
			an1=(50.0-y)/(x-50.0);
			an2=atan(an1);
			an2=((180.0*7.0)/22.0)*an2;
			an3=an2+90.0;
			if(an3<=angle)
			{
				cout<<"Case #"<<h<<":"<<" black\n";
			}else
			{
				cout<<"Case #"<<h<<":"<<" white\n";
			}
		}else if(x<=50 && y<=50)
		{
			an1=(50.0-y)/(50.0-x);
			an2=atan(an1);
			an2=((180.0*7.0)/22.0)*an2;			
			an3=90.0-an2;
			an3=an3+180.0;
			if(an3<=angle)
			{
				cout<<"Case #"<<h<<":"<<" black\n";
			}else
			{
				cout<<"Case #"<<h<<":"<<" white\n";
			}
		}else if(x==50 && y>=50)
		{
			if(angle>=360.0)
	    	{
	    		cout<<"Case #"<<h<<":"<<" black\n";
			}else
			{
				cout<<"Case #"<<h<<":"<<" white\n";
			}
		}else if(x<=50 && y>=50)
		{
			an1=(y-50.0)/(50.0-x);
			an2=atan(an1);
			an2=((180.0*7.0)/22.0)*an2;			
			an3=an2+270.0;
			if(an3<=angle)
			{
				cout<<"Case #"<<h<<":"<<" black\n";
			}else
			{
				cout<<"Case #"<<h<<":"<<" white\n";
			}
		}
	}
}
