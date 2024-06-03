#include "bits/stdc++.h"

#define all(x) ((x).begin(), (x).end())

using namespace std;

const long long MOD = 998244353LL;
const int N = (int)2e5+2;
const int block = (int)900;

vector<pair<int, int>> E[N];
vector<pair<int, int>> H[N];

int main(){
    //~ printf("%lld\n", (long long)1e18);
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    vector<int> a(n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    vector<bool> heavy(n, false);
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        E[a].push_back({b, c});
        E[b].push_back({a, c});
        if((int)E[a].size() > block){
            heavy[a] = true;
        }
        if((int)E[b].size() > block){
            heavy[b] = true;
        }
    }
    vector<int> regtoh(n, 0);
    vector<int> htoreg;
    for(int i=0; i<n; i++){
        if(heavy[i]){
            htoreg.push_back(i);
            regtoh[i] = htoreg.size() - 1;
        }
    }
    vector<multiset<long long>> heavyNodeEdges(htoreg.size(), multiset<long long>());
    unordered_map<long long, pair<long long, long long>> mk;
    for(int i=0; i<n; i++){
        for(auto [j, c] : E[i]){
            if(heavy[j]){
                H[i].push_back({j, c});
            }
            if(heavy[i]){
                heavyNodeEdges[regtoh[i]].insert(c);
                mk[1LL * i * n + j] = {c, 0};
                mk[1LL * j * n + i] = {c, 0};
            }
        }
    }
    vector<int> b(q);
    for(int i=0; i<q; i++){
        scanf("%d", &b[i]);
        b[i]--;
    }
    reverse(b.begin(), b.end());
    vector<long long> plusw(n, 0LL);
    vector<long long> muevete(n, 0);
    for(int i=0; i<q; i++){
        int u = b[i];
        long long minEdge = (long long)1e18;
        if(heavy[u]){
            minEdge = *heavyNodeEdges[regtoh[u]].begin();
        } else {
            for(auto [v, w] : E[u]){
                long long c = w + plusw[v];
                minEdge = min(minEdge, c);
            }
        }
        muevete[u] = minEdge % MOD;
        
        // update the edges with destination at a heavy node
        // H[u] contains only heavy nodes connected to node u
        for(auto [v, w] : H[u]){
            int hv = regtoh[v];
            pair<long long, long long> c = mk[1LL * u * n + v];
            heavyNodeEdges[hv].erase(heavyNodeEdges[hv].find(c.first + c.second));
            
            mk[1LL * u * n + v] = {c.first, minEdge};
            heavyNodeEdges[hv].insert(c.first + minEdge);
        }
        
        // Update the egdes with destination at a light node
        plusw[u] = minEdge;
    }
    long long ans = 0;
    for(int i=0; i<n; i++){
        ans = (((a[i] * muevete[i]) % MOD) + ans) % MOD;
    }
    printf("%lld\n", ans);
    
    return 0;
}
