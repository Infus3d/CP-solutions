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

const int N = 752;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int kx[] = {-2, -1, +1, +2, +2, +1, -1, -2};
int ky[] = {-1, -2, -2, -1, +1, +2, +2, +1};

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, -1, 0, +1};

int n, m, a[N][N], vis[N][N], knight[N][N];
char s[N][N];
int rx, ry, tx, ty;

int ok(int x, int y){
  return (0 <= x && x < n && 0 <= y && y < m);
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++){
    scanf(" %s", s[i]);
    for(int j=0; j<m; j++){
      if(s[i][j] == 'T') tx = i, ty = j;
      else if(s[i][j] == 'R') rx = i, ry = j;
      else if(s[i][j] == 'K'){
        knight[i][j] = 1;
        for(int k=0; k<8; k++){
          int ni = i+kx[k];
          int nj = j+ky[k];
          if(ok(ni, nj))
            a[ni][nj]++;
        }
      }
    }
  }
  
  queue<pii> Q;
  Q.push({rx, ry}); vis[rx][ry] = 1;
  while(!Q.empty()){
    pii cur = Q.front(); Q.pop();
    //~ printf("x:%d, y:%d\n", cur.ff, cur.ss);
    for(int i=0; i<4; i++){
      int nx = cur.ff + dx[i];
      int ny = cur.ss + dy[i];
      while(ok(nx, ny)){
        //~ printf("i:%d, nx:%d, ny:%d\n", i, nx, ny);
        if(vis[nx][ny] == 0){
          if(knight[nx][ny]){
            if(a[nx][ny] == 0){
              for(int j=0; j<8; j++){
                int tempx = nx + kx[j];
                int tempy = ny + ky[j];
                if(ok(tempx, tempy)){
                  a[tempx][tempy]--;
                  if(a[tempx][tempy] == 0){
                    bool done = false;
                    for(int k=0; k<4; k++){
                      int xx = tempx + dx[k];
                      int yy = tempy + dy[k];
                      while(ok(xx, yy)){
                        if(vis[xx][yy]){
                          done = true;
                          break;
                        }
                        if(knight[xx][yy] == 1) 
                          break;
                        xx += dx[k];
                        yy += dy[k];
                      }
                      if(done) break;
                    }
                    if(done){
                      vis[tempx][tempy] = 1;
                      Q.push({tempx, tempy});
                    }
                  }
                }
              }
              if(!vis[nx][ny]){
                vis[nx][ny] = 1;
                Q.push({nx, ny});
              }
            }
            break;
          }
          else if(a[nx][ny] == 0){
            vis[nx][ny] = 1;
            knight[nx][ny] = 0;
            Q.push({nx, ny});
          }
        }
        nx += dx[i];
        ny += dy[i];
      }
    }
  }
  
  if(vis[tx][ty] == 1) puts("yes");
  else puts("no");
}
/*
6 6
.K...T
.K....
KK....
......
...KKK
R..K..

ans: no
*/

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
