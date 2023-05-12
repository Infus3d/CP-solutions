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
const int MOD = 1e6+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

char X[N], Y[N];

void solve(){
  int m, n;
  scanf("%s%s", X, Y);
  m = strlen(X);
  n = strlen(Y);
  vector<vector<int>> c(m+1, vector<int>(n+1, 0));
  vector<vector<int>> cnt(m+1, vector<int>(n+1, 0));
  for(int i=0; i<=m; i++){
    c[i][0] = 0;
    cnt[i][0] = 1;
  }
  for(int i=0; i<=n; i++){
    c[0][i] = 0;
    cnt[0][i] = 1;
  }
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      if(X[i-1] == Y[j-1]){
        c[i][j] = c[i-1][j-1] + 1;
        cnt[i][j] = cnt[i-1][j-1];
      } else {
        c[i][j] = max(c[i-1][j], c[i][j-1]);
        if(c[i-1][j] > c[i][j-1]){
          cnt[i][j] = cnt[i-1][j];
        } else if(c[i][j-1] > c[i-1][j]){
          cnt[i][j] = cnt[i][j-1];
        } else {
          cnt[i][j] = (cnt[i-1][j] + cnt[i][j-1]) % MOD;
          if(c[i-1][j-1] == c[i-1][j]){
            cnt[i][j] = (cnt[i][j] - cnt[i-1][j-1] + MOD) % MOD;
          }
        }
      }
    }
  }
  printf("%d\n", cnt[m][n]);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int i=1; i<=testcase; i++){
    printf("Case %d: ", i);
    solve();
  }
  return 0;
}
