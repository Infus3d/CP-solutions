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

const int N = 1e2+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

vector<string> v;
string s;
int n, m, cur, vis[N][N];

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, -1, 0, +1};

bool ok(int x, int y){
  return x >= 0 && x < n && y >= 0 && y < m;
}

int getScore(int x, int y){
  for(int i=0; i<4; i++){
    int xx = x+dx[i];
    int yy = y+dy[i];
    if(ok(xx, yy) && v[xx][yy] <= v[x][y])
      return 0;
  }
  return (v[x][y]-'0'+1);
}

void dfs(int x, int y){
  vis[x][y] = 1; cur++;
  for(int i=0; i<4; i++){
    int xx = x+dx[i];
    int yy = y+dy[i];
    if(ok(xx, yy) && !vis[xx][yy])
      dfs(xx, yy);
  }
}

void solve(){
  freopen("input.txt", "r", stdin);
  while(cin >> s){
    v.pb(s); n++;
    umax(m, (int)s.length());
  }
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(v[i][j] == '9')
        vis[i][j] = 1;
  
  
  ll ans = 1LL;
  vector<int> basins;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(!vis[i][j]){
        cur = 0; dfs(i, j);
        basins.pb(cur);
      }
  sort(all(basins));
  assert(sz(basins) >= 3);
  for(int i=sz(basins)-1; i>=sz(basins)-3; i--)
    ans *= basins[i];
  
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
