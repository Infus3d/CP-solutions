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

int lvl[N], par[N], cnt;
set<int> E[N];
vector<int> G[N];

void dfs(int u, int p){
    par[u] = p;
    lvl[u] = lvl[p] + 1;
    for(int v : G[u]){
        if(v != p){
            E[u].insert(v);
            dfs(v, u);
        }
    }
}

void solve(){
    int n; scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        int a, b; scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    vector<int> v(n);
    for(int i=0; i<n; i++){
        v[i] = i+1;
    }
    sort(all(v), [&](int x, int y){
        return lvl[x] > lvl[y];
    });
    vector<bool> out(n+1, false);
    int ans = 0;
    for(int u : v){
        if(out[u]) continue;
        // printf("u: %d, lvl[u]: %d, ans: %d\n", u, lvl[u], ans);
        if(u == 1){
            ans += 2;
            out[u] = true;
        } else if(sz(E[par[u]]) == 1) {
            ans += 1;
            out[u] = out[par[u]] = true;
            if(par[u] != 1){
                E[par[par[u]]].erase(par[u]);
            }
        } else {
            assert(sz(E[u]) == 0);
            out[u] = true;
            ans += 2;
            E[par[u]].erase(u);
        }
    }
    printf("%d\n", ans);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
