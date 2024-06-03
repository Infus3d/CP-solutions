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

vector<pair<int, int>> E[8][12];
int airports[9][12];

void solve(){
    int k, m, n;
    scanf("%d%d%d", &k, &n, &m);
    for(int i=0; i<m; i++){
        int u, v, d, z;
        scanf("%d%d%d%d", &u, &v, &d, &z);
        u--, v--, d--;
        E[d][u].push_back({v, z});
    }
    for(int i=0; i<k*n; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        airports[b][a] += c;
    }
    for(int i=0; i<n; i++){
        for(int u=0; u<k; u++){
            for(auto [v, c] : E[i][u]){
                if(airports[i][u] < c){
                    puts("suboptimal");
                    return;
                }
                airports[i][u] -= c;
                airports[i+1][v] += c;
            }
        }
        for(int u=0; u<k; u++){
            airports[i+1][u] += airports[i][u];
        }
    }
    puts("optimal");
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
