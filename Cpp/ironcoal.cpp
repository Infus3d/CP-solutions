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

void solve(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> a(m), b(k);
    vector<vector<int>> E(n+1), RE(n+1);
    for(int i=0; i<m; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<k; i++){
        scanf("%d", &b[i]);
    }
    for(int i=1; i<=n; i++){
        int nn; scanf("%d", &nn);
        for(int j=0; j<nn; j++){
            int aa; scanf("%d", &aa);
            E[i].push_back(aa);
            RE[aa].push_back(i);
        }
    }
    vector<vector<int>> dist(3, vector<int>(n+1));
    auto bfs = [&](vector<int> st, vector<int> &dist, vector<vector<int>> &EE){
        for(int i=0; i<sz(dist); i++){
            dist[i] = MOD;
        }
        queue<int> Q;
        for(int i : st){
            dist[i] = 0;
            Q.push(i);
        }
        while(!Q.empty()){
            int u = Q.front(); Q.pop();
            for(int v : EE[u]){
                if(dist[v] > dist[u] + 1){
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
        }
    };
    bfs(vector<int>{1}, dist[0], E);
    bfs(a, dist[1], RE);
    bfs(b, dist[2], RE);
    int ans = MOD;
    for(int i=1; i<=n; i++){
        if(dist[0][i] != MOD && dist[1][i] != MOD && dist[2][i] != MOD){
            ans = min(ans, dist[0][i] + dist[1][i] + dist[2][i]);
        }
    }
    if(ans == MOD) puts("impossible");
    else printf("%d\n", ans);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
