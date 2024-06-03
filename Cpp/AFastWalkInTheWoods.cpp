#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2500+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m, ans = -1;
int vis[N][4];
int x[N], y[N];
struct edge{
    int u, v, k;
} edges[N*4];
vector<pair<int, int>> E[N];
int stNode, stDir;
vector<int> edgeList;

void dfs(int u, int dir){
    if(vis[u][dir]){
        stNode = u, stDir = dir;
        return;
    }
    vis[u][dir] = 1;
    for(auto [v, idx] : E[u]){
        
    }
}

void solve(){
    scanf("%d%d", &n, &m);
    assert(m <= 4*n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].k);
        E[edges[i].u].push_back({edges[i].v, i});
        E[edges[i].v].push_back({edges[i].u, i});
    }
    
    char cc;
    scanf("%d %c", &stNode, &cc);
    if(cc == 'N') stDir = 0;
    else if(cc == 'E') stDir = 1;
    else if(cc == 'S') stDir = 2;
    else stDir = 3;
    
    while(ans == -1){
        edgeList.clear();
        dfs(stNode, stDir);
    }
    printf("%d %d\n", x[ans], y[ans]);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
