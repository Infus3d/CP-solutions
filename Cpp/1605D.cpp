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
 
const int N = 2e5+7;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+7;
 
template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);


int n, a, b, col[N], chosen, cnt[2];
vector<int> E[N], group[2];

void dfs(int x, int par, int color){
    cnt[color]++;
    col[x] = color;
    for(int i : E[x])
        if(i != par)
            dfs(i, x, color^1);
}

void solve(){
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        scanf("%d%d", &a, &b);
        E[a].pb(b);
        E[b].pb(a);
    }
    dfs(1, 0, 0);
    chosen = (cnt[0] <= cnt[1]) ? 0 : 1;
    
    int &num = cnt[chosen];
    for(int i=0; i<19; i++){
        if(num & (1<<i)){
            for(int j=(1<<i); j<(1<<(i+1)); j++)
                group[chosen].pb(j);
        }
    }
    
    int node = 1;
    for(int i : group[chosen]){
        while(node < i)
            group[chosen^1].pb(node++);
        node++;
    }
    while(node <= n) group[chosen^1].pb(node++);
    
    for(int i=1; i<=n; i++){
        printf("%d ", group[col[i]].back());
        group[col[i]].ppb();
    }
    puts("");
    
    for(int i=1; i<=n; i++)
        E[i].clear();
    cnt[0] = cnt[1] = 0;
    group[0].clear(), group[1].clear();
}

int main(){
    int testcase;
    
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    
	return 0;
}
