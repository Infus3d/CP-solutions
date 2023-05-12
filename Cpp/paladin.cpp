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

void solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  vector<pair<int, int>> v[26];
  char s[10];
  vector<pair<pair<int, int>, int>> seg;
  vector<vector<int>> mat(26, vector<int>(26, -1));
  for(int i=0; i<n; i++){
    int a;
    scanf("%s%d", s, &a);
    v[s[0]-'a'].push_back({s[1]-'a', a});
    seg.push_back({{s[0] - 'a', s[1] - 'a'}, a});
    mat[s[0]-'a'][s[1]-'a'] = a;
  }
  
  if(k == 2){
    int ans = MOD;
    for(int i=0; i<26; i++){
      if(mat[i][i] != -1){
        umin(ans, mat[i][i]);
      }
    }
    if(ans >= MOD) ans = -1;
    printf("%d\n", ans);
    return;
  }
  
  vector<vector<int>> dp(k+1, vector<int>(26, 0));
  int ans = MOD;
  for(int i=0; i<n; i++){
    for(int j=0; j<k; j++){
      for(int u=0; u<26; u++){
        dp[j][u] = MOD;
      }
    }
    if(mat[seg[i].ff.ss][seg[i].ff.ff] != -1)
      dp[1][seg[i].ff.ss] = seg[i].ss + mat[seg[i].ff.ss][seg[i].ff.ff];
    // printf("i -> %d\n", i);
    int half = (k + 1) / 2;
    for(int j=1; j<half-1; j++){
      for(int u=0; u<26; u++){
        for(auto l : v[u]){
          // printf("%d %d %d\n", j, u, l.ff);
          // printf("size -> %d\n", sz(dp[j+1]));
          if(mat[l.ff][u] != -1)
            umin(dp[j+1][l.ff], dp[j][u] + l.ss + mat[l.ff][u]);
        }
      }
    }
    for(int j=0; j<26; j++){
      if(k % 2 == 1)
        umin(ans, dp[half-1][j]);
      else if(mat[j][j] != -1)
        umin(ans, dp[half-1][j] + mat[j][j]);
    }
  }
  if(ans >= MOD) ans = -1;
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
