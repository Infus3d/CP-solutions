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

const int N = 1e4+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m, q, A;
vector<pair<int, int>> E[N];
int dist[10][N];

void dijkstra(int st, int u0){
    set<pair<int, int>> setik;
    for(int i=0; i<n; i++){
        dist[st][i] = MOD;
    }
    dist[st][u0] = 0;
    setik.insert({0, u0});
    while(!setik.empty()){
        auto [w, u] = *setik.begin();
        setik.erase(setik.begin());
        if(dist[st][u] != w) continue;
        for(auto [v, c] : E[u]){
            if(dist[st][v] > w + c){
                dist[st][v] = w + c;
                setik.insert({dist[st][v], v});
            }
        }
    }
}

void solve(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<=n; i++){
        E[i].clear();
    }
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        E[a].push_back({b, c});
        E[b].push_back({a, c});
    }
    scanf("%d", &q);
    vector<int> idols(q);
    vector<int> perm(q);
    for(int i=0; i<q; i++){
        scanf("%d", &idols[i]);
        perm[i] = i;
    }
    scanf("%d", &A);
    for(int i=0; i<=q; i++){
        dijkstra(i, i < q ? idols[i] : 0);
    }
    int ans = 0;
    if(q > 0){
        do{
            int airLeft = A - dist[q][idols[perm[0]]];
            for(int i=0; i<sz(idols); i++){
                if(airLeft < 0) break;
                if(airLeft - dist[perm[i]][0] >= 0){
                    ans = max(ans, i+1);
                }
                if(i+1 < sz(idols)){
                    airLeft = airLeft - dist[perm[i]][idols[perm[i+1]]];
                }
            }
        } while(next_permutation(perm.begin(), perm.end()));
    }
    printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
