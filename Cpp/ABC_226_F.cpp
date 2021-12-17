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
 
const int N = 5e1+2;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, k, C[N][N], f[N];
map<ll, int> dp[N];

int lcm(int x, int y){
    return x / __gcd(x, y) * y;
}

int pw(int x, int y){
    if(y == 0) return 1;
    if(y == 1) return x;
    int tr = pw(x, y/2);
    tr = (1LL * tr * tr) % MOD;
    if(y%2) tr = (1LL * tr * x) % MOD;
    return tr;
}

int main(){
    scanf("%d%d", &n, &k);
    C[0][0] = 1;
    for(int i=1; i<=n; i++){
        C[i][0] = C[i][i] = 1;
        for(int j=1; j<i; j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
    f[0] = 1;
    for(int i=1; i<=n; i++)
        f[i] = (1LL * f[i-1] * i) % MOD;
    
    dp[0][1] = 1;
    for(int i=0; i<n; i++)
        for(auto mk : dp[i])
            for(int j=1; j+i<=n; j++)
                dp[i+j][lcm(j, mk.ff)] = (dp[i+j][lcm(j, mk.ff)] + ((1LL * mk.ss * ( (1LL * f[j-1] * C[n-i-1][j-1]) % MOD)) % MOD)) % MOD;
    
    int ans = 0;
    for(auto i : dp[n])
        ans = (ans + (1LL * i.ss * pw(i.ff, k))%MOD) % MOD;
    printf("%d\n", ans);
    
	return 0;
}
