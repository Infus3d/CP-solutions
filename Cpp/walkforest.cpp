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
const int MOD = (int)2e9;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

vector<pair<int, int>> E[K];
int dist[K], dp[K];

int dfs(int x, int par){
    if(x == 2) return 1;
    if(dp[x] != -1) return dp[x];
    dp[x] = 0;
    for(auto [v, c] : E[x]){
        if(dist[x] > dist[v]){
            dp[x] += dfs(v, x);
        }
    }
    return dp[x];
}

int solve(){
    int n, m;
    scanf("%d", &n);
    if(n == 0){
        return false;
    }
    scanf("%d", &m);
    for(int i=0; i<=n; i++){
        E[i].clear();
        dist[i] = MOD;
        dp[i] = -1;
    }
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        E[a].push_back({b, c});
        E[b].push_back({a, c});
    }
    
    dist[2] = 0;
    set<pair<int, int>> setik;
    setik.insert({0, 2});
    while(!setik.empty()){
        auto [w, u] = *setik.begin();
        setik.erase(setik.begin());
        if(dist[u] != w) continue;
        for(auto [v, c] : E[u]){
            if(dist[v] > w + c){
                dist[v] = w + c;
                setik.insert({dist[v], v});
            }
        }
    }
    
    printf("%d\n", dfs(1, 0));
    return true;
}

int main(){
    // int testcase = 1;
    // scanf("%d", &testcase);
    while(solve()){
        
    }
    return 0;
}
