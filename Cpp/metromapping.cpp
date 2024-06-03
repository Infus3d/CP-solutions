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

const int N = 15;
const int M = 1e2+5;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int m, n, A, dist[M][M][N];
vector<pair<int, int>> E[M];
int T, B;

void solve(){
    scanf("%d%d%d", &m, &n, &A);
    vector<int> v;
    for(int i=0; i<n; i++){
        int k; scanf("%d", &k);
        for(int j=0; j<k; j++){
            int a; scanf("%d", &a);
            v.push_back(a);
        }
        for(int j=0; j<k-1; j++){
            int a = v[j], b = v[j+1];
            E[a].push_back({b, i});
            E[b].push_back({a, i});
        }
        v.clear();
    }
    // db;
    queue<pair<int, pair<int, int>>> Q;
    Q.push({1, {0, 0}});
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[1][0][0] = 0;
    // printf("---> %d\n", dist[0][0][1]);
    while(!Q.empty()){
        int u = Q.front().first;
        auto [uk, ucolor] = Q.front().second;
        Q.pop();
        
        for(auto [v, vcolor] : E[u]){
            int vk = uk + ((u == 1 || ucolor == vcolor) ? 0 : 1);
            if(vk <= m && dist[v][vk][vcolor] > dist[u][uk][ucolor] + 1){
                dist[v][vk][vcolor] = dist[u][uk][ucolor] + 1;
                Q.push({v, {vk, vcolor}});
            }
        }
    }
    
    // minimum for each switch at town hall (over all colors)
    vector<int> townHall;
    for(int i=0; i<=m; i++){
        int mini = dist[m][i][0];
        for(int j=0; j<n; j++){
            umin(mini, dist[m][i][j]);
        }
        townHall.push_back(mini);
    }
    
    scanf("%d", &T);
    while(T--){
        scanf("%d", &B);
        long long ans = (long long)1e18;
        for(int i=0; i<=m; i++){
            ans = min(ans, 1LL * i * B + 1LL * townHall[i] * A);
        }
        printf("%lld\n", ans);
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
