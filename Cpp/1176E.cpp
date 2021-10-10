/*
ID : omarmuh1
PROG : test
LANG : C++11
*/

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

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
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 you_made_my_day

using namespace std;
using namespace __gnu_pbds;

const int N = 2e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int vis[N], lvl[N], q, n, m, sum[2];
vector <int> E[N];
vector <int> v[2];

void dfs(int x, int par){
    vis[x] = 1;
    lvl[x] = lvl[par] + 1;
    sum[lvl[x]&1]++;
    v[lvl[x]&1].pb(x);
    
    for(int i : E[x])
        if(!vis[i])
            dfs(i, x);
}

int main(){
    scanf("%d", &q);
    
    while(q--){
        scanf("%d%d", &n, &m);
        
        for(int i=1; i<=n; i++) E[i].clear();
        for(int i=0; i<=n; i++) vis[i] = lvl[i] = 0;
        sum[0] = sum[1] = 0;
        v[0].clear(); v[1].clear();
        
        for(int i=1; i<=m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            
            E[a].pb(b);
            E[b].pb(a);
        }
        
        dfs(1, 0);
        
        int flag = 0;
        
        if(sum[0] > sum[1])
            flag = 1;
        
        printf("%d\n", sz(v[flag]));
        for(int i : v[flag])
            printf("%d ", i);
        puts("");
    }
    
	return 0;
}

