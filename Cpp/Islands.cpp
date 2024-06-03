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
const int K = 52;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m, cnt = 0;
int vis[K][K];
char g[K][K];

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, -1, 0, +1};

bool ok(int x, int y){
    return (0 <= x && x < n && 0 <= y && y < m);
}

void dfs(int x, int y){
    vis[x][y] = cnt;
    for(int i=0; i<4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(ok(newx, newy) && !vis[newx][newy] && (g[newx][newy] == 'L' || g[newx][newy] == 'C')){
            dfs(newx, newy);
        }
    }
}

void solve(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf(" %c", &g[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(g[i][j] == 'L' && !vis[i][j]){
                ++cnt;
                dfs(i, j);
            }
        }
    }
    printf("%d\n", cnt);
}

int main(){
    int testcase = 1;
    // scanf("%d", &testcase);
    while(testcase--){
        solve();
    }
    return 0;
}
