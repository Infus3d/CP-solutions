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
const int K = 3e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m;
vector<pair<int, int>> E[K];
vector<int> U, V, W;
vector<int> par;
vector<bool> inMST, curST;

int find(int x){
    if(par[x] == x){
        return x;
    }
    return par[x] = find(par[x]);
}

int dfs(int u, int par, int dest){
    if(u == dest){
        return m;
    }
    int ret = -1;
    for(auto [v, idx] : E[u]){
        if(v != par && curST[idx]){
            ret = dfs(v, u, dest);
            if(ret != -1){
                if(ret == m && !inMST[idx]){
                    ret = idx;
                }
                break;
            }
        }
    }
    return ret;
}

void solve(){
    scanf("%d%d", &n, &m);
    U = vector<int>(m);
    V = vector<int>(m);
    W = vector<int>(m);
    vector<pair<int, int>> ordering;
    inMST = vector<bool>(m, false);
    curST = vector<bool>(m, false);
    par = vector<int>(n+1, 0);
    for(int i=0; i<=n; i++){
        par[i] = i;
    }
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &U[i], &V[i], &W[i]);
        E[U[i]].push_back({V[i], i});
        E[V[i]].push_back({U[i], i});
        ordering.push_back({W[i], i});
        if(i < n-1) curST[i] = true;
    }
    sort(all(ordering));
    for(auto [w, idx] : ordering){
        int u = U[idx], v = V[idx];
        if(find(u) != find(v)){
            par[find(v)] = find(u);
            inMST[idx] = true;
        }
    }
    vector<pair<int, int>> ans;
    for(auto [w, idx] : ordering){
        int u = U[idx], v = V[idx];
        if(inMST[idx] && !curST[idx]){
            int newIdx = dfs(u, -1, v);
            curST[idx] = true;
            curST[newIdx] = false;
            ans.push_back({newIdx, idx});
        }
    }
    printf("%d\n", sz(ans));
    for(auto [i, j] : ans){
        printf("%d %d\n", i+1, j+1);
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
