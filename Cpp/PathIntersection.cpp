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

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, q, lvl[N], tin[N], tout[N], timeCnt;
int P[N][19];
vector<int> E[N];

void dfs(int u, int par){
    tin[u] = ++timeCnt;
    lvl[u] = lvl[par] + 1;
    P[u][0] = par;
    for(int v : E[u]){
        if(v != par){
            dfs(v, u);
        }
    }
    tout[u] = ++timeCnt;
}

void build_lca(){
    for(int j=1; j<19; j++){
        for(int i=1; i<=n; i++){
            if(P[i][j-1] > 0){
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}

int lca(int x, int y){
    // printf("Finding lca for x: %d, y: %d\n", x, y);
    if(lvl[y] > lvl[x]){
        swap(x, y);
    }
    for(int i=18; i>=0; i--){
        if(lvl[x] - (1<<i) >= lvl[y]){
            x = P[x][i];
        }
    }
    if(x == y){
        return x;
    }
    for(int i=18; i>=0; i--){
        if(P[x][i] != P[y][i] && P[x][i] > 0){
            x = P[x][i];
            y = P[y][i];
        }
    }
    // printf("final x: %d, y: %d, lca: %d\n", x, y, P[x][0]);
    // assert(P[x][0] == P[y][0]);
    return P[x][0];
}

void solve(){
    scanf("%d%d", &n, &q);
    for(int i=0; i<n-1; i++){
        int a, b; scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    dfs(1, 0);
    build_lca();
    while(q--){
        vector<int> nodes(4);
        for(int i=0; i<4; i++){
            scanf("%d", &nodes[i]);
        }
        set<pair<int, int>> setik;
        for(int i=0; i<2; i++){
            for(int j=2; j<4; j++){
                int ancestor = lca(nodes[i], nodes[j]);
                setik.insert({lvl[ancestor], ancestor});
            }
        }
        int childCount = 0;
        for(int i=0; i<4; i++){
            int a = (*setik.rbegin()).second;
            int b = nodes[i];
            if(tin[a] <= tin[b] && tout[b] <= tout[a]){
                childCount++;
            }
        }
        if(lvl[lca(nodes[0], nodes[1])] > (*setik.rbegin()).first
            || lvl[lca(nodes[2], nodes[3])] > (*setik.rbegin()).first){
                puts("-1");
        } else if(sz(setik) == 1){
            int a = (*setik.rbegin()).second;
            printf("%d %d\n", a, a);
        } else {
            int a = (*setik.rbegin()).second;
            int b = (*(++setik.rbegin())).second;
            if(childCount >= 3){
                printf("%d %d\n", a, a);
            } else {
                printf("%d %d\n", a, b);
            }
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
