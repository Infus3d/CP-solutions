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

const int N = 65;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, lvl[N], ata[N];
long long edge[N];
vector<int> E[N];

void dfs(int u, int par){
    lvl[u] = lvl[par]+1;
    ata[u] = par;
    for(int v : E[u]){
        if(v != par){
            dfs(v, u);
        }
    }
}

void propogate(int u, int par){
    if(u != 1){
        edge[u] *= edge[par];
    }
    for(int v : E[u]){
        if(v != par){
            propogate(v, u);
        }
    }
}

vector<int> getPrimes(int x){
    vector<int> primes;
    for(int i=2; i<1000; i++){
        bool ok = true;
        for(int j=2; j*j<=i; j++){
            if(i % j == 0){
                ok = false;
            }
        }
        if(ok) primes.push_back(i);
        if((int)primes.size() >= x){
            return primes;
        }
    }
    return primes;
}


void solve(){
    scanf("%d", &n);
    for(int i=0; i<=n; i++){
        edge[i] = -1;
    }
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    dfs(1, 0);
    vector<int> primes = getPrimes(60);
    vector<int> leaves;
    for(int i=2; i<=n; i++){
        if(sz(E[i]) == 1){
            leaves.push_back(i);
            // printf("%d ", i);
        }
    }
    edge[1] = 1;
    for(int t=0; t<(int)leaves.size(); t++){
        // puts("**************");
        vector<pair<pair<int, int>, int>> v;
        for(int leaf : leaves){
            int depth = 0;
            int cur = leaf;
            while(edge[cur] == -1){
                depth++;
                cur = ata[cur];
            }
            // printf("t: %d, leaf: %d, depth: %d\n", t, leaf, depth);
            v.push_back({{depth, lvl[leaf]}, leaf});
        }
        sort(all(v));
        reverse(all(v));
        int leaf = v[0].ss;
        while(edge[leaf] == -1){
            edge[leaf] = primes[t];
            leaf = ata[leaf];
        }
    }
    propogate(1, 0);
    for(int i=1; i<=n; i++){
        printf("%lld ", edge[i]);
    }
    puts("");
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
