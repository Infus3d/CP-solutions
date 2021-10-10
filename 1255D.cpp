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

const int N = 1e2+7;
const ll MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

int arr[N][N], cn, n, m, k, testCase;
char ch, type[65], d[N][N];

int main(){
	for(int i='A'; i<='Z'; i++)	type[cn++] = char(i);
	for(int i='a'; i<='z'; i++)	type[cn++] = char(i);
	for(int i='0'; i<='9'; i++)	type[cn++] = char(i);
	
	scanf("%d", &testCase);
	
	while(testCase--){
		scanf("%d%d%d", &n, &m, &k);
		int cnt = 0;
		
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++){
				scanf(" %c", &ch);
				
				if(ch == '.')
					arr[i][j] = 0;
				else
					arr[i][j] = 1, cnt++;
			}
		
		int each = cnt/k;
		int rem = cnt%k;
		int cur = 0, nxt = 0;
		int left = n*m, r = 1, c = 1;
		
		while(left > 0){
			if(arr[r][c] == 1){
				if(cur == each + (rem > 0)){
					cur = 0;
					nxt++;
					rem--;
				}
				
				cur++;
			}
			
			d[r][c] = type[nxt];
			
			int rr = r;
			r += ((c == 1 && r%2 == 0) || (c == m && r%2 == 1)) ? 1 : 0;
			c += (r != rr) ? 0 : (r % 2 == 1) ? 1 : -1;
			left--;
		}
		
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++)
				printf("%c", d[i][j]);
			puts("");
		}
	}
	
	return 0;
}