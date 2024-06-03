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
const int M = 1e6+5;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m;
int parent[N], theSize[N];
int a[M], b[M], w[M];
long long ans = 0, mstCost = 0;
bool selectedEdge[M], isRemovedEdge[M*2];
vector<pii> E[N];
vector<pair<pii, int>> toAdd[N], toRemove[N];
multiset<int> nonMstEdges[N];

int P[N][18], lvl[N];

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void dfsForLca(int u, int par){
    lvl[u] = !par ? 0 : lvl[par] + 1;
    P[u][0] = par;
    for(auto [v, idx] : E[u]){
        if(v != par){
            dfsForLca(v, u);
        }
    }
}

void build_lca(){
    for(int j=1; j<18; j++){
        for(int i=1; i<=n; i++){
            if(P[P[i][j-1]][j-1] > 0){
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}

int lca(int u, int v){
    if(lvl[v] > lvl[u]){
        swap(u, v);
    }
    for(int i=17; i>=0; i--){
        if(lvl[u] - (1<<i) >= lvl[v]){
            u = P[u][i];
        }
    }
    if(u == v){
        return u;
    }
    for(int i=17; i>=0; i--){
        if(P[u][i] > 0 && P[u][i] != P[v][i]){
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[u][0];
}

void dfs(int u, int par, int weight){
    if(!toAdd[u].empty()){
        int idx = toAdd[u].back().ff.ff;
        nonMstEdges[u].insert(w[idx]);
        toAdd[u].pop_back();
    }
    for(auto [v, idx] : E[u]){
        if(v != par){
            dfs(v, u, w[idx]);
            if(nonMstEdges[u].size() < nonMstEdges[v].size()){
                swap(nonMstEdges[u], nonMstEdges[v]);
            }
            nonMstEdges[u].insert(nonMstEdges[v].begin(), nonMstEdges[v].end());
        }
    }
    for(auto [e, id] : toRemove[u]){
        isRemovedEdge[id] = true;
    }
    for(auto [e, id] : toRemove[u]){
        auto [idx, v] = e;
        if(nonMstEdges[u].find(w[idx]) != nonMstEdges[u].end()){
            nonMstEdges[u].erase(nonMstEdges[u].find(w[idx]));
        }
        while(!toAdd[v].empty()){
            auto [ee, vidx] = toAdd[v].back();
            auto [i, t] = ee;
            toAdd[v].pop_back();
            if(!isRemovedEdge[vidx]){
                nonMstEdges[u].insert(w[i]);
                break;
            }
        }
    }
    if(u != 1){
        ans = max(ans, (long long)*nonMstEdges[u].begin() - weight);
    }
}

void solve(){
    scanf("%d%d", &n, &m);
    vector<int> sortedEdges(m);
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &a[i], &b[i], &w[i]);
        sortedEdges[i] = i;
    }
    sort(all(sortedEdges), [&](int x, int y){
        return w[x] < w[y];
    });
    for(int i=1; i<=n; i++){
        parent[i] = i;
        theSize[i] = 1;
    }
    for(int i : sortedEdges){
        int aa = findParent(a[i]), bb = findParent(b[i]);
        if(aa != bb){
            if(theSize[bb] > theSize[aa]) swap(aa, bb);
            theSize[aa] += theSize[bb];
            parent[bb] = aa;
            mstCost += w[i];
            
            E[a[i]].push_back({b[i], i});
            E[b[i]].push_back({a[i], i});
            
            selectedEdge[i] = true;
        } else {
            selectedEdge[i] = false;
        }
    }
    dfsForLca(1, 0);
    build_lca();
    reverse(all(sortedEdges));
    for(int i : sortedEdges){
        if(!selectedEdge[i]){
            int anc = lca(a[i], b[i]);
            if(lvl[a[i]] > lvl[b[i]]){
                swap(a[i], b[i]);
            }
            toAdd[b[i]].push_back({{i, b[i]}, (i+1)*2});
            toRemove[anc].push_back({{i, b[i]}, (i+1)*2});
            if(anc != a[i]){
                toAdd[a[i]].push_back({{i, a[i]}, i+1});
                toRemove[anc].push_back({{i, a[i]}, i+1});
            }
        }
    }
    dfs(1, 0, -1);
    printf("%lld\n", mstCost + ans);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
