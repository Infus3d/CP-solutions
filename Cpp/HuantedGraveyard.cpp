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

vector<pair<int, int>> E[K];

void solve(int n, int m){
    int g; scanf("%d", &g);
    vector<bool> grave(n*m, false);
    for(int i=0; i<g; i++){
        int x, y; scanf("%d%d", &x, &y);
        int idx = (x * m) + y;
        grave[idx] = true;
    }
    vector<vector<pair<int, int>>> E(K, vector<pair<int, int>>());
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int idx = (i * m) + j;
            if(!grave[idx] && idx != n*m-1){
                if(idx % m > 0 && !grave[idx - 1]){
                    E[idx].push_back({idx-1, 1});
                }
                if(idx % m < (m-1) && !grave[idx + 1]){
                    E[idx].push_back({idx+1, 1});
                }
                if(idx - m >= 0 && !grave[idx - m]){
                    E[idx].push_back({idx-m, 1});
                }
                if(idx + m < n*m && !grave[idx + m]){
                    E[idx].push_back({idx+m, 1});
                }
            }
        }
    }
    int h; scanf("%d", &h);
    for(int i=0; i<h; i++){
        int x1, y1, x2, y2, t;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &t);
        int idx1 = (x1 * m) + y1;
        int idx2 = (x2 * m) + y2;
        E[idx1].clear();
        E[idx1].push_back({idx2, t});
    }
    vector<int> dist(n*m, MOD);
    dist[0] = 0;
    for(int k=0; k<n*m-1; k++){
        for(int i=0; i<n*m; i++){
            for(auto [j, w] : E[i]){
                if(dist[i] != MOD && dist[i] + w < dist[j]){
                    dist[j] = dist[i] + w;
                }
            }
        }
    }
    for(int i=0; i<n*m; i++){
        for(auto [j, w] : E[i]){
            if(dist[i] != MOD && dist[i] + w < dist[j]){
                puts("Never");
                return;
            }
        }
    }
    if(dist[n*m-1] == MOD){
        puts("Impossible");
    } else {
        printf("%d\n", dist[n*m-1]);
    }
}

int main(){
    // scanf("%d", &testcase);
    while(true){
        int n, m;
        scanf("%d%d", &n, &m);
        if(!n && !m) break;
        solve(n, m);
    }
    return 0;
}
