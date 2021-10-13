#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"
 
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define db puts("*****")
#define mid(x , y) ((x+y)>>1)
#define ff first
#define ss second
#define all(x)	x.begin(),x.end()
#define ll long long
#define sqr(x)	((x)*(x))
#define pii pair <int , int>
#define pll pair <ll, ll>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day
 
using namespace std;
// using namespace __gnu_pbds;
 
const int N = 1e5+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
const double epsil = 0.00001; 

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

double ans;
double l, r;
double d, s;

double getVal(double m){
	return 0.0 + m + s - (m * cosh(d / (2.0 * m)));
}

int main(){
	scanf("%lf%lf", &d, &s);
	
	l = 0.0, r = 1000000000.0;
	while(l < r){
		double m = (l + r) / 2.0;
		double value = getVal(m);
		//~ printf("**** %.4lf %.4lf %.20lf %.4lf\n", l, r, value, m);
		if(abs(value) <= epsil){
			ans = m;
			break;
		}
		
		if(value < 0)
			l = m;
		else
			r = m;
	}
	/**
	if(ans == -1){
		if(abs(getVal(r)) < abs(getVal(l)))
			ans = r;
		else
			ans = l;
	}**/
	printf("%.4lf\n", 2.0 * ans * sinh(d / (2.0 * ans)));
	//~ printf("%.50lf\n", 2.0 * 506.0 * sinh(d / (2.0 * 506.0)));
	
	return 0;
}
