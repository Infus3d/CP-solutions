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

const int N = 2e5+7;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a, T b) { a += b; while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> omar;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, m, d[2][N], lvl[N];
int P[N][21];
vector<int> E[N];
char s[N];

void dfs(int x, int y){
    P[x][0] = y;
    lvl[x] = lvl[y]+1;
    d[0][x] += d[0][y];
    d[1][x] += d[1][y];
    
    for(int i : E[x])
        if(i != y)
            dfs(i, x);
}

void build_lca(){
    for(int j=1; j<20; j++)
        for(int i=1; i<=n; i++)
            if(P[P[i][j-1]][j-1] > 0)
                P[i][j] = P[P[i][j-1]][j-1];
}

int lca(int x, int y){
    if(lvl[x] < lvl[y])
        swap(x, y);
    
    for(int i=19; i>=0; i--)
        if(lvl[x] - (1<<i) >= lvl[y])
            x = P[x][i];
    
    if(x == y) return x;
    
    for(int i=19; i>=0; i--)
        if(P[x][i] > 0 && P[x][i] != P[y][i])
            x = P[x][i], y = P[y][i];
    
    return P[x][0];
}

int main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for(int i=0; i<n; i++)  d[s[i]-'G'][i+1] = 1;
    for(int i=1; i<n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        
        E[a].pb(b);
        E[b].pb(a);
    }
    dfs(1, 0);
    build_lca();
    
    while(m--){
        int a, b; char c;
        scanf("%d%d %c", &a, &b, &c);
        
        int tr = lca(a, b);
        int ans = d[c-'G'][a] - d[c-'G'][tr] + d[c-'G'][b] - d[c-'G'][tr] + d[c-'G'][tr] - d[c-'G'][P[tr][0]];
        printf("%d", ans > 0 ? 1 : 0);
    }
    puts("");
    
    return 0;
}

