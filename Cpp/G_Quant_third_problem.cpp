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

int dfs(int x, int y, vector<vector<int>> &vis, vector<string> &B){
  int cnt = 0;
  vis[x][y] = 1;
  for(int dx=-1; dx<=1; dx++){
    for(int dy=-1; dy<=1; dy++){
      if(dx+dy == 0 || dx == dy) continue;
      int newx = x + dx;
      int newy = y + dy;
      if(0 <= newx && newx < (int)vis.size() && 0 <= newy && newy < (int)vis[0].size() 
          && !vis[newx][newy] && B[newx][newy] == '#'){
        cnt += dfs(newx, newy, vis, B);
      }
    }
  }
  return cnt+1;
}

vector<int> solution(vector<string> &B){
  int n = (int)B.size();
  if(n == 0) return vector<int>{0, 0, 0};
  int m = (int)B[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  vector<int> R(3);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(B[i][j] == '#' && vis[i][j] == 0){
        int cnt = dfs(i, j, vis, B);
        assert(0 < cnt && cnt < 4);
        R[cnt-1]++;
      }
    }
  }
  return R;
}

void solve(){
  int n; scanf("%d", &n);
  vector<string> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  vector<int> ans = solution(v);
  printf("%d %d %d\n", ans[0], ans[1], ans[2]);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
