#include<bits/stdc++.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<float.h>

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


struct lines{
	double m;
	int pos;
};


void mergep(struct lines*line,int l,int mid,int r){
	int i,j,k,n1 = mid-l+1,n2 = r-mid;
	struct lines L[n1],R[n2];
	for(i = 0;i<n1;i++){
		L[i].m = line[l+i].m;
		L[i].pos = line[l+i].pos;
	}

	for(i = 0;i<n2;i++){
		R[i].m = line[mid+1+i].m;
		R[i].pos = line[mid+1+i].pos;
	}

	i = 0;
	j = 0;
	k = l;

	while(i<n1 && j<n2){
		if(L[i].m<=R[j].m){
			line[k].m = L[i].m;
			line[k].pos = L[i].pos;
			i++;
		}

		else{
			line[k].m = R[j].m;
			line[k].pos = R[j].pos;
			j++;
		}

		k++;
	}

	while(i<n1){
		line[k].m = L[i].m;
		line[k].pos = L[i].pos;
		i++;
		k++;
	}

	while(j<n2){
		line[k].m = R[j].m;
		line[k].pos = R[j].pos;
		j++;msortp
		k++;
	}
}

void msortp(struct lines *m,int l,int r){
	if(l<r){
		int mid = l+(r-l)/2;
		msortp(m,l,mid);
		msortp(m,mid+1,r);
		mergep(m,l,mid,r);
	}
}

int main(){
	int t,n,i,a,b,c,ctr,ans,j,ctr2;

	scanf("%d",&t);
	while(t--){
		double *C;
		struct lines *line;
		ans = 1;
		ctr = 1;
		n = read();
		C = (double*)calloc(n,sizeof(double));
		line = (struct lines*)calloc(n,sizeof(struct lines));
		for(i = 0;i<n;i++){
			a = read();
			b = read();
			c = read();
			if(b!=0)
			    line[i].m = (double)(-a)/(double)b;
			else
                line[i].m = DBL_MAX;
            line[i].pos = i;
			if(b!=0)
			    C[i] = (double)(-c)/(double)b;
			else
                C[i] = (double)(-c)/(double)a;
		}
		msortp(line,0,n-1);
		vector <double> yint;
		for(i = 1;i<n;i++){

			ctr2 = 1;
			if(line[i].m == line[i-1].m){
				ctr++;
				yint.push_back(C[line[i-1].pos]);
			}
			else{
				yint.push_back(C[line[i-1].pos]);
				sort(yint.begin(),yint.end());
				for(j = 1;j<ctr;j++){
					if(yint[j] != yint[j-1])
					ctr2++;
				}
				if(ctr2>ans)
				ans = ctr2;
				yint.erase(yint.begin(),yint.end());
				ctr = 1;
			}
		}
		yint.push_back(C[line[i-1].pos]);
		sort(yint.begin(),yint.end());
		for(j = 1;j<ctr;j++){
			if(yint[j] != yint[j-1])
			ctr2++;
		}
		if(ctr2>ans)
		ans = ctr2;
		yint.erase(yint.begin(),yint.end());
		if(n == 1)
		puts("1");
		else
		printf("%d\n",ans);
		free((void*)C);
		free((void*)line);
	}
	return 0;
}
