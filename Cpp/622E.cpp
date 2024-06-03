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

const int N = 5e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int maxLvl;
vector<int> E[N];
vector<int> lvl, leafCnt;

void dfs(int u, int par) {
    lvl[u] = lvl[par] + 1;
    for (int v : E[u]) {
        if (v != par) {
            dfs(v, u);
        }
    }
    
    if (sz(E[u]) == 1) {
        leafCnt[lvl[u]]++;
    }
    umax(maxLvl, lvl[u]);
}

void solve(){
    int n; scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int a, b; scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    
    int ans = 0;
    lvl.assign(n+1, 0);
    leafCnt.assign(2*(n+1), 0);
    
    for(int v : E[1]) {
        maxLvl = 0;
        dfs(v, 1);
        
        for (int i = 1; i < maxLvl; i++) {
            if (leafCnt[i] > 0) {
                leafCnt[i+1] += leafCnt[i] - 1;
            }
        }
        // printf("maxLvl: %d, leafCnt[maxLvl]: %d\n", maxLvl, leafCnt[maxLvl]);
        umax(ans, leafCnt[maxLvl] + maxLvl - 1);
        
        for (int i = 1; i <= maxLvl; i++) {
            leafCnt[i] = 0;
        }
    }
    
    printf("%d\n", ans);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--) {
        solve();
    }
    return 0;
}
