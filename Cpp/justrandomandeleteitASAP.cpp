#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define pb push_back
#define N 100000
#define ll long long
using namespace std;
 
vector<pair<ll,ll> > v;
bool par=false;
 
bool checkpar(ll a,ll b){
	return (a&1 && b&1);
}
 
ll solve(int n){
	ll ar=0,s1,s2,s3,m=0,m2,imax,vmax;
	s1=0;
	s2=v[n-1].second;imax=n-1;
	for(int i=n-2;i>=0;i--){
		s3=v[i].second;
		if(s3<=s2){
			if(s3<=s1)continue;
			s1=s3;
			ar=v[i].first*s1;
			m=ar>m?ar:m;
		}
		else{ 
		 	s2=s3;
		 	vmax=v[imax].second;
		 	if(s2>>1 >= vmax)
		 		{
		 			ar=(s2*v[i].first)>>1;
		 			m=ar>=m?ar:m;
		 			par=checkpar(s2,v[i].first);
		 		}
		 	else{
		 		ar=vmax*v[i].first;
		 		if(ar>m){m=ar;par=false;}
		 	}
 
		 	imax=i;
		}
 
	}
 
	return m;
}
 
int main()
{
	int n,k=0;
	ll l,w,max=0,m2;
 
	cin >> n;
	for(int i=0;i<n;i++){
		cin>>l>>w;
		 if(l<=w) v.pb(make_pair(l,w));
		 else v.pb(make_pair(w,l));
	}
	sort(v.begin(),v.end());
	max=solve(n);
	m2=(v[n-1].first*v[n-1].second)>>1;
	if(m2>=max){par=checkpar(v[n-1].first,v[n-1].second);max=m2;}
 
	if(par)
		cout<<max<<".5";
	else
		cout<<max<<".0";
 
	return 0;
}
