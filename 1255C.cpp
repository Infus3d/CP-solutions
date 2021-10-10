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

const int N = 1e5+7;
const ll MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

int d[N][3], n, cnt[N], arr[N], cn, last1, last2;
map<pii, set<int>> mk;

int main(){
	scanf("%d", &n);
	
	for(int i=1; i<=n-2; i++){
		scanf("%d%d%d", &d[i][0], &d[i][1], &d[i][2]);
		cnt[d[i][0]]++; cnt[d[i][1]]++; cnt[d[i][2]]++;
		
		mk[{d[i][0], d[i][1]}].insert(d[i][2]); mk[{d[i][1], d[i][0]}].insert(d[i][2]);
		mk[{d[i][1], d[i][2]}].insert(d[i][0]); mk[{d[i][2], d[i][1]}].insert(d[i][0]);
		mk[{d[i][0], d[i][2]}].insert(d[i][1]); mk[{d[i][2], d[i][0]}].insert(d[i][1]);
	}
	
	for(int i=1; i<=n; i++){
		sort(d[i], d[i]+3, [](int a, int b){
			return cnt[a] <= cnt[b];
		});
		
		if(cnt[d[i][0]] == 1){
			last2 = d[i][1];
			last1 = d[i][2];
			
			arr[++cn] = d[i][0]; 
			arr[++cn] = d[i][1];
			arr[++cn] = d[i][2];
			
			break;
		}
	}
	
	while(cn < n){
		mk[{last2, last1}].erase(arr[cn-2]);
		arr[++cn] = *mk[{last2, last1}].begin();
		last2 = last1;
		last1 = arr[cn];
	}
	
	for(int i=1; i<=n; i++)
		printf("%d ", arr[i]);
	puts("");
	
	return 0;
}