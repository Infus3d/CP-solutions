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
const int K = 1e6+1;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

vector<int> P(K);

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, -1, 0, +1};

void check(vector<vector<int>> &v){
    int n = sz(v)-1, m = sz(v[0])-1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=0; k<4; k++){
                int ii = i + dx[k];
                int jj = j + dy[k];
                if(1 <= ii && ii <= n && 1 <= jj && jj <= m){
                    // printf("%d %d, %d %d\n", i, j, ii, jj);
                    assert(P[abs(v[i][j] - v[ii][jj])] != 0);
                }
            }
        }
    }
    vector<bool> vis(n*m+1, 0);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            assert(vis[v[i][j]] == 0);
            vis[v[i][j]] = 1;
        }
    }
    int tot = 0;
    for(int i=1; i<=n*m; i++){
        tot += vis[i];
    }
    assert(tot == n*m);
}

// fun problem :|
void solve(int _n = -1, int _m = -1){
    int n, m;
    scanf("%d%d", &n, &m);
    // n = _n, m = _m;
    vector<vector<int>> a(n+1, vector<int>(m+1, 0));
    int l = (n+1)/2, r = n;
    for(int i=1; i<=n; i++){
        int cur = (i % 2) ? l : r;
        for(int j=(i-1)*m+1; j<=(i)*m; j++){
            a[cur][j - ((i-1)*m)] = j;
        }
        if(i % 2 == 1) l--;
        else r--;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            printf("%d ", a[i][j]);
        }
        puts("");
    }
    // check(a);
}

int main(){
    // P[1] = 1;
    // for(int i=2; i<K; i++){
        // if(P[i] != 0) continue;
        // for(int j=i+i; j<K; j+=i){
            // P[j] = 1;
        // }
    // }
    int testcase = 1;
    scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    
    // for(int i=4; i<=200; i++){
        // for(int j=4; j<=200; j++){
            // printf("Starting on i: %d, j:%d\n", i, j);
            // solve(i, j);
        // }
    // }
    return 0;
}
