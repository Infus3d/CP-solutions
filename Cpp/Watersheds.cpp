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

const int N = 100+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m, cnt;
int d[N][N], vis[N][N];

int dx[] = {-1, 0, 0, +1};
int dy[] = {0, -1, +1, 0};

int ok(int x, int y){
    return (0 <= x && x < n) && (0 <= y && y < m);
}

void dfs(int x, int y){
    vector<pair<int, int>> v;
    for(int i=0; i<4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(ok(newx, newy) && d[newx][newy] < d[x][y]){
            v.push_back({d[newx][newy], i});
            
        }
    }
    if(!v.empty()){
        sort(all(v));
        int newx = x + dx[v[0].ss];
        int newy = y + dy[v[0].ss];
        if(!vis[newx][newy]){
            dfs(newx, newy);
        }
        vis[x][y] = vis[newx][newy];
        return;
    }
    vis[x][y] = ++cnt;
}

void solve(){
    scanf("%d%d", &n, &m);
    cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vis[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &d[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j]){
                dfs(i, j);
            }
        }
    }
    map<int, char> mk;
    char cur = 'a';
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mk.find(vis[i][j]) == mk.end()){
                mk[vis[i][j]] = cur;
                cur++;
            }
            printf("%c ", mk[vis[i][j]]);
        }
        puts("");
    }
}

int main(){
    int testcase = 1;
    scanf("%d", &testcase);
    for(int t=1; t<=testcase; t++){
        printf("Case #%d:\n", t);
        solve();
    }
    return 0;
}
