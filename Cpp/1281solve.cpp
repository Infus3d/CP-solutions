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
 
const int N = 5e3+7;
const int MOD = 1e9+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, mn[N], tott, k, a, b, mx, tot, d[N], e[N], f[N], dp[N][N];
vector<int> E[N];
ll ans;

int main(){
    scanf("%d%d%d", &n, &m, &k); tot = k;
    for(int i=1; i<=n; i++)
        scanf("%d%d%d", &d[i], &e[i], &f[i]);
    for(int i=1; i<=n; i++){
        if(d[i] > tot)
            return 0 * printf("-1\n");
        tot += e[i];
    }
    tott = tot; mn[n+1] = MOD;
    for(int i=n; i>=1; i--)
        mn[i] = min(mn[i+1], tott-d[i+1]), tott -= e[i];
    
    for(int i=1; i<=m; i++){
        scanf("%d%d", &a, &b);
        E[max(a, b)].pb(min(a, b));
    }
    for(int i=1; i<=n; i++)
        sort(all(E[i]), [] (int x, int y){
            return f[x] >= f[y];
        });
    
    sort(f+1, f+n+1);
    for(int i=n; i>=n-mn[1]+1; i--)
        ans += f[i];
    printf("%lld\n", ans);
    
    return 0;
}
