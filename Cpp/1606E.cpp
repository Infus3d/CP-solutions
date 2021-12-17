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
 
const int N = 5e2+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, x, c[N][N], dp[N][N];

int add(int x, int y){
    x += y;
    if(x >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y){
    return (1LL * x * y) % MOD;
}

int main(){
    scanf("%d%d", &n, &x);
    for(int i=0; i<=n; i++){
        c[i][0] = c[i][i] = 1;
        for(int j=1; j<i; j++)
            c[i][j] = add(c[i-1][j], c[i-1][j-1]);
    }
    
    dp[n][0] = 1;
    for(int i=n; i>1; i--){
        for(int j=0; j<x; j++){
            int nextJ = min(x, j+i-1), pawa = 1;
            for(int k=i; k>=0; k--){
                dp[k][nextJ] = add(dp[k][nextJ], mul(dp[i][j], mul(c[i][i-k], pawa)));
                pawa = mul(pawa, (nextJ-j));
            }
        }
    }
    
    int ans = 0;
    for(int i=0; i<=x; i++)
        ans = add(ans, dp[0][i]);
    printf("%d\n", ans);
	
    return 0;
}
