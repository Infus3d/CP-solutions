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

const int N = 3e3+5;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m, vis[N][N];
char s[N][N];

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, -1, 0, +1};

int ok(int x, int y){
  return (0 <= x && x < n && 0 <= y && y < m && s[x][y] != '#');
}

//~ void dfs(int x, int y){
  //~ printf("%d %d %c\n", x, y, s[x][y]);
  //~ fprintf(stderr, "x->%d, y->%d, s->%c, vis->%d\n", x, y, s[x][y], vis[x][y]);
  //~ vis[x][y] = 1;
  //~ for(int i=0; i<4; i++){
    //~ if(ok(x + dx[i], y + dy[i]) && vis[x + dx[i]][y + dy[i]] == 0){
      //~ dfs(x + dx[i], y + dy[i]);
    //~ }
  //~ }
  //~ int cnt = 0;
  //~ for(int i=0; i<4; i++){
    //~ int newx = x + dx[i];
    //~ int newy = y + dy[i];
    //~ if(ok(newx, newy) && (vis[newx][newy] == 1 || s[newx][newy] == '^'))
      //~ cnt++;
  //~ }
  //~ if(cnt >= 2){
    //~ s[x][y] = '^';
  //~ }
  //~ vis[x][y] = 2;
//~ }

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++){
    scanf("%s", s[i]);
    for(int j=0; j<m; j++)
      vis[i][j] = 0;
  }
  stack<pair<int, int>> st;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(s[i][j] == '^' && vis[i][j] == 0){
        //~ puts("Fresh start");
        //~ fprintf(stderr, "i->%d, j->%d\n", i, j);
        //~ dfs(i, j);
        st.push({i, j});
        while(!st.empty()){
          auto [x, y] = st.top();
          //~ fprintf(stderr, "x->%d, y->%d, vis->%d\n", x, y, vis[x][y]);
          vis[x][y]++;
          if(vis[x][y] == 5){
            st.pop();
            int cnt = 0;
            for(int k=0; k<4; k++){
              int newx = x + dx[k];
              int newy = y + dy[k];
              if(ok(newx, newy) && (vis[newx][newy] < 5 || s[newx][newy] == '^'))
                cnt++;
            }
            if(cnt >= 2){
              s[x][y] = '^';
            }
            continue;
          }
          for(int k=0; k<4; k++){
            int newx = x + dx[k];
            int newy = y + dy[k];
            if(ok(newx, newy) && (vis[newx][newy] == 0)){
              st.push({newx, newy});
              break;
            }
          }
        }
      }
    }
  }
  //~ fprintf(stderr, "If this appears, the run is successful\n");
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(s[i][j] == '^'){
        int cnt = 0;
        for(int k=0; k<4; k++){
          int newx = i + dx[k];
          int newy = j + dy[k];
          if(ok(newx, newy) && s[newx][newy] == '^')
            cnt++;
        }
        if(cnt < 2){
          puts("Impossible");
          return;
        }
      }
    }
  }
  //~ fprintf(stderr, "maybe here too\n");
  puts("Possible");
  for(int i=0; i<n; i++){
    printf("%s\n", s[i]);
  }
  //~ fprintf(stderr, "possibly\n");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int i=1; i<=testcase; i++){
    printf("Case #%d: ", i);
    solve();
    //~ fprintf(stderr, "case number %d\n", i);
  }
  return 0;
}
