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

const int N = 1e3+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m;
int d[N][N], vis[N][N];

int fx[] = {-1, -1, -1, 0, 0, +1, +1, +1};
int fy[] = {-1, 0, +1, -1, +1, -1, 0, +1};

int dx[] = {0, 0, +1, +1};
int dy[] = {0, +1, 0, +1};

bool ok(int x, int y){
  return 1 <= x && (x+1) <= n && 1 <= y && (y+1) <= m;
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      scanf("%d", &d[i][j]);
    }
  }
  queue<pair<pair<int, int>, int>> Q;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(ok(i, j)){
        bool flag = true;
        for(int k=0; k<4; k++){
          if(d[i][j] != d[i+dx[k]][j+dy[k]]){
            flag = false;
            break;
          }
        }
        if(flag == true){
          vis[i][j] = 1;
          Q.push({{i, j}, d[i][j]});
        }
      }
    }
  }
  vector<pair<pair<int, int>, int>> ans;
  while(!Q.empty()){
    auto [x, y] = Q.front().first;
    auto z = Q.front().second;
    Q.pop();
    ans.push_back({{x, y}, z});
    for(int i=0; i<4; i++){
      d[x+dx[i]][y+dy[i]] = 0;
    }
    for(int i=0; i<8; i++){
      int newx = x + fx[i];
      int newy = y + fy[i];
      if(!ok(newx, newy) || vis[newx][newy]) continue;
      bool flag = true;
      int theor = 0;
      for(int j=0; j<4; j++){
        int tempx = newx + dx[j];
        int tempy = newy + dy[j];
        theor |= d[tempx][tempy];
      }
      for(int j=0; j<4; j++){
        int tempx = newx + dx[j];
        int tempy = newy + dy[j];
        if(d[tempx][tempy] > 0 && d[tempx][tempy] != theor){
          flag = false;
          break;
        }
      }
      if(flag == true){
        vis[newx][newy] = 1;
        Q.push({{newx, newy}, theor});
      }
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(d[i][j] > 0){
        puts("-1");
        return;
      }
    }
  }
  printf("%d\n", sz(ans));
  for(int i=sz(ans)-1; i>=0; i--){
    printf("%d %d %d\n", ans[i].ff.ff, ans[i].ff.ss, ans[i].ss);
  }
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
