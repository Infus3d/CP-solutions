#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"
 
#define mp make_pair
#define pb emplace_back
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
 
const int N = 5e1+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e4+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, k;
int pw[N][K], fact[N];

int get(int v){
    return (1LL * pw[v][k] * fact[v]) % MOD;
}

int main(){
    scanf("%d%d", &n, &k);
    fact[0] = 1;
    for(int i=1; i<=n; i++){
        fact[i] = (1LL * fact[i-1] * i) % MOD;
        pw[i][0] = 1;
        for(int j=1; j<=k; j++)
            pw[i][j] = (1LL * pw[i][j-1] * i) % MOD;
    }
    
    int ans = 0;
    for(int i=2; i<=n; i++)
        ans = (ans + get(i)) % MOD;
    printf("%d\n", ans+1);
    
	return 0;
}
