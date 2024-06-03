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

const int N = 1e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m, L;
int par[N], siz[N];
struct maEdge{
    int u, v, c;
} edge[N+10];
vector<pair<int, int>> E[N];
int extraEdges[N];
vector<bool> isExtra;

// tree stuff
vector<pair<int, int>> TE[N];
int P[N][19], lvl[N];
long long C[N][19];

// dijstra stuff
vector<vector<long long>> dist;

int findPar(int x){
    if(par[x] == x) return x;
    return par[x] = findPar(par[x]);
}

void unite(int x, int y){
    if(siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
}

void dfs(int x, int par, int cost){
    lvl[x] = lvl[par]+1;
    P[x][0] = par;
    C[x][0] = cost;
    for(auto[v, c] : TE[x]){
        if(v != par){
            dfs(v, x, c);
        }
    }
}

void build_lca(){
    for(int j=1; j<19; j++){
        for(int i=1; i<=n; i++){
            if(P[i][j-1] > 0){
                P[i][j] = P[P[i][j-1]][j-1];
                C[i][j] = C[i][j-1] + C[P[i][j-1]][j-1];
            }
        }
    }
}

long long lcaCost(int x, int y){
    if(lvl[x] < lvl[y]){
        swap(x, y);
    }
    long long ret = 0;
    for(int i=18; i>=0; i--){
        if(lvl[x] - (1<<i) >= lvl[y]){
            ret += C[x][i];
            x = P[x][i];
        }
    }
    if(x == y) return ret;
    for(int i=18; i>=0; i--){
        if(P[x][i] > 0 && P[y][i] > 0 && P[x][i] != P[y][i]){
            ret += C[x][i] + C[y][i];
            x = P[x][i];
            y = P[y][i];
        }
    }
    return (ret + C[x][0] + C[y][0]);
}

void dijkstra(int stNode, int edgeIdx){
    // printf("Initiating dijkstra for edgeIdx: %d, and starting node: %d\n", edgeIdx, stNode);
    dist[edgeIdx][stNode] = 0;
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> Q;
    Q.push({0LL, stNode});
    while(!Q.empty()){
        auto [c, u] = Q.top(); Q.pop();
        for(auto [v, w] : E[u]){
            if(c + w < dist[edgeIdx][v]){
                dist[edgeIdx][v] = c + w;
                Q.push({dist[edgeIdx][v], v});
            }
        }
    }
}

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        par[i] = i;
        siz[i] = 1;
    }
    isExtra = vector<bool>(n+10, false);
    for(int i=1; i<=n; i++){
        edge[i].u = i;
        scanf("%d%d", &edge[i].v, &edge[i].c);
        int para = findPar(edge[i].u), parb = findPar(edge[i].v);
        if(para != parb){
            unite(para, parb);
            TE[edge[i].v].push_back({edge[i].u, edge[i].c});
            TE[edge[i].u].push_back({edge[i].v, edge[i].c});
        } else {
            isExtra[i] = true;
        }
        E[edge[i].u].push_back({edge[i].v, edge[i].c});
        E[edge[i].v].push_back({edge[i].u, edge[i].c});
    }
    // dfs(1, 0);
    // build_lca();
    scanf("%d", &L);
    for(int i=n+1; i<=n+L; i++){
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].c);
        int para = findPar(edge[i].u), parb = findPar(edge[i].v);
        if(para != parb){
            unite(para, parb);
            TE[edge[i].u].push_back({edge[i].v, edge[i].c});
            TE[edge[i].v].push_back({edge[i].u, edge[i].c});
        } else {
            isExtra[i] = true;
        }
        E[edge[i].u].push_back({edge[i].v, edge[i].c});
        E[edge[i].v].push_back({edge[i].u, edge[i].c});
    }
    for(int i=1; i<=n; i++){
        if(lvl[i] == 0){
            dfs(i, 0, 0);
        }
    }
    build_lca();
    dist = vector<vector<long long>>(L+2, vector<long long>(n+1, (long long)1e18));
    for(int i=1; i<=n+L; i++){
        if(isExtra[i]){
            int component = findPar(edge[i].u);
            assert(component == findPar(edge[i].v));
            // extraEdges[component].push_back(i);
            dijkstra(edge[i].u, extraEdges[component]++);
        }
    }
    // for(int j=0; j<L+1; j++){
        // printf("The distances from u of edge %d\n", j);
        // for(int i=1; i<=n; i++){
            // printf("v->%d, dist[u][v]->%lld\n", i, dist[j][i]);
        // }
    // }
    scanf("%d", &m);
    while(m--){
        int a, b; scanf("%d%d", &a, &b);
        int para = findPar(a), parb = findPar(b);
        if(para != parb){
            puts("-1");
        } else {
            long long ans = lcaCost(a, b);
            // printf("The lca cost: %lld\n", ans);
            assert(extraEdges[para] <= L+1);
            for(int i=0; i<extraEdges[para]; i++){
                umin(ans, dist[i][a] + dist[i][b]);
            }
            printf("%lld\n", ans);
        }
    }
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
