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

const int N = 12;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

string s;
vector<string> v;
int vis[N][N], d[N][N], n, m;
int dx[] = {0, -1, -1, -1, 0, +1, +1, +1};
int dy[] = {-1, -1, 0, +1, +1, +1, 0, -1};

bool ok(int x, int y){
  return x >= 0 && x < n && y >= 0 && y < m;
}

void solve(){
  freopen("input.txt", "r", stdin);
  //~ freopen("input2.txt", "r", stdin);
  while(cin >> s){
    v.pb(s);
  }
  n = sz(v), m = (int)v[0].length();
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      d[i][j] = v[i][j] - '0';
  
  int ans = 0;
  for(int step=0; step<100000; step++){
    queue<pii> Q;
    memset(vis, 0, sizeof(vis));
  
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++){
        d[i][j]++;
        if(d[i][j] > 9){
          vis[i][j] = 1;
          Q.push({i, j});
        }
      }
    
    while(!Q.empty()){
      pii tr = Q.front(); Q.pop(); ans++;
      for(int i=0; i<8; i++){
        int xx = tr.ff+dx[i];
        int yy = tr.ss+dy[i];
        if(ok(xx, yy)){
          d[xx][yy]++;
          if(d[xx][yy] > 9 && !vis[xx][yy]){
            vis[xx][yy] = 1;
            Q.push({xx, yy});
          }
        }
      }
    }
    
    int cn = 0;
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        if(d[i][j] > 9){
          cn++;
          d[i][j] = 0;
        }
    
    if(cn == n*m){
      printf("** %d\n", step+1);
      return;
    }
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
