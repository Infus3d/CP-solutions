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

const int N = 2e2+7;
const int INF = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += INF; a %= INF; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

ll dp[N], calc[N][N];
char s[N];
int n;

int main(){
	scanf("%d", &n);
	
	while(n--){
		memset(dp, 0, sizeof(dp));
		memset(calc, -1, sizeof(calc));
		
		scanf("%s", s);
		
		int size = strlen(s);
		
		for(int i=0; i<size; i++){
			ll cur = 0;
			
			for(int j=i; j<size; j++){
				cur = cur*10 + (s[j] - '0');
				
				if(cur > INT_MAX)
					break;
				
				calc[i][j] = cur;
			}
		}
		
		for(int i=size-1; i>=0; i--){
			if(s[i] == '0')
				dp[i] = dp[i+1];
			else{
				ll temp = 0;
				
				for(int j=1; j<=10; j++)
					if(calc[i][i+j-1] != -1)
						umax(temp, dp[i+j] + calc[i][i+j-1]);
				
				dp[i] = temp;
			}
		}
		
		printf("%lld\n", dp[0]);
	}
	
	return 0;
}

