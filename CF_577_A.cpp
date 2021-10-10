/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

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
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day

using namespace std;
using namespace __gnu_pbds;

const int N = 1e3+7;
const int INF = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += INF; a %= INF; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int ans, d[N], M[N][5], n, m;
char s[N];

int main(){
	scanf("%d%d", &n, &m);
	
	for(int i=0; i<n; i++){
		scanf("%s", s);
		
		for(int j=0; j<m; j++)
			M[j][s[j]-'A']++;
	}
	
	for(int i=0; i<m; i++)	scanf("%d", &d[i]);
	
	for(int i=0; i<m; i++){
		int a = 0;
		
		for(int j=0; j<5; j++)
			umax(a, M[i][j]);
		
		ans += d[i]*a;
	}
		
	printf("%d\n", ans);
	
	return 0;
}

