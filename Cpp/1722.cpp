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

char s[52][52];
int d[52][52];

int dx[] = {-1, -1, -1, +1, +1, +1, +1, -1};
int dy[] = {-1, +1, +1, +1, +1, -1, -1, -1};

int fx[] = {-1, -1, 0, 0, +1, +1, 0, 0};
int fy[] = {0, 0, +1, +1, 0, 0, -1, -1};

int ex[] = {-1, -1, -1, 0, +1, +1, +1, 0};
int ey[] = {-1, 0, +1, +1, +1, 0, -1, -1};

int n, m;

bool ok(int x, int y){
  return 0 <= x && x < n && 0 <= y && y < m;
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=0; i<=n; i++){
    if(i < n)
      scanf("%s", s[i]);
    for(int j=0; j<=m; j++)
      d[i][j] = 0;
  }
  int cnt = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(s[i][j] == '*' && d[i][j] == 0){
        for(int k=0; k<8; k++){
          int cx = i+dx[k];
          int cy = j+dy[k];
          if(ok(cx, cy)){
            int tx = i+fx[k];
            int ty = j+fy[k];
            if(s[cx][cy] != '*' || s[tx][ty] != '*') continue;
            if(s[cx][cy] == '*' && d[cx][cy] != 0){
              puts("NO");
              return;
            }
            if(s[tx][ty] == '*' && d[tx][ty] != 0){
              puts("NO");
              return;
            }
            d[cx][cy] = d[tx][ty] = d[i][j] = ++cnt;
          }
        }
      }
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      for(int k=0; k<8; k++){
        int x = i+ex[k];
        int y = j+ey[k];
        if(ok(x, y) && d[x][y] > 0 && d[i][j] > 0 && d[x][y] != d[i][j]){
          puts("NO");
          return;
        }
      }
      if(s[i][j] == '*' && d[i][j] == 0){
        puts("NO");
        return;
      }
    }
  }
  puts("YES");
}

int main(){
  int testcase = 1;
  cin >> testcase;
  while(testcase--){
    solve();
  }
  return 0;
}
