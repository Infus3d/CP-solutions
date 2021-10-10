/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

#include "bits/stdc++.h"
//#include "ext/pb_ds/assoc_container.hpp"
//#include "time.h"

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
//using namespace __gnu_pbds;

const int N = 1e3+7;
const ll MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

int testCase, n, m;
pii arr[N];

int main(){
	scanf("%d", &testCase);
	
	while(testCase--){
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++) scanf("%d", &arr[i].ff), arr[i].ss = i;
		sort(arr+1, arr+n+1);
		
		if(m != n || m < 3){
			printf("-1\n");
			continue;
		}
		
		int ans = 0;
		for(int i=1; i<=n; i++)
			ans += 2*arr[i].ff;
		
		printf("%d\n", ans);
		for(int i=1; i<=n; i++)
			printf("%d %d\n", arr[i].ss, arr[(i == n ? 1 : i+1)].ss);
	}
	
	return 0;
}