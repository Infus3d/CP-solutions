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

const int N = 50+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

bool bridge;
int n, m, cnt;
int tin[N], fup[N];
vector<int> E[N], R[N];

void dfs(int u, int par){
    tin[u] = fup[u] = ++cnt;
    for(int v : E[u]){
        if(v != par){
            if(!tin[v]){
                dfs(v, u);
                fup[u] = min(fup[u], fup[v]);
                if(fup[v] > tin[u]){
                    bridge = true;
                }
                R[u].push_back(v);
            } else {
                fup[u] = min(fup[u], tin[v]);
                if(tin[v] < tin[u]){
                    R[u].push_back(v);
                }
            }
        }
    }
}

void solve(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    bridge = false;
    dfs(1, 0);
    if(bridge){
        puts("NO");
    } else {
        puts("YES");
        for(int i=1; i<=n; i++){
            for(int v : R[i]){
                printf("%d %d\n", i, v);
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
