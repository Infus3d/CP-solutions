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
const int K = 17;
const int M = (1<<17);
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }
template<class T> T umod(T a, T mod){ if(a >= mod) a -= mod; return a; }

int n, q, prec[N][N];
int pw[N][K], dp[M][K];
char s[N], t[K+1];
bool precMask[N][N][K];

void solve(){
  scanf("%d", &n);
  scanf("%s", s);
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++){
    if(s[i] == '?'){
      a[i] = 1;
      b[i] = 1;
    }
  }
  for(int i=1; i<n; i++) a[i] += a[i-1];
  for(int i=n-2; i>=0; i--) b[i] += b[i+1];
  for(int i=0; i<K; i++){
    pw[0][i] = 1;
    for(int j=1; j<=n; j++){
      pw[j][i] = (1LL * pw[j-1][i] * (i+1)) % MOD;
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
      int inner = ((i-1) < (j+1) ? 0 : prec[j+1][i-1]);
      int outer = (s[i] == s[j] ? (s[i] == '?') : (min(s[i], s[j]) == '?')-1);
      if(inner == -1 || outer == -1){
        prec[j][i] = -1;
        continue;
      }
      else{
        prec[j][i] = inner + outer;
        for(int k=0; k<K; k++){
          precMask[j][i][k] = (precMask[j][i][k] || ((j+1) <= (i-1) ? precMask[j+1][i-1][k] : false));
        }
        if(s[i] != s[j]) precMask[j][i][max(s[i], s[j])-'a'] = true;
      }
      int d = (j > 0 ? a[j-1] : 0) + (i < n-1 ? b[i+1] : 0);
      int mask = 0;
      for(int k=0; k<K; k++){
        if(precMask[j][i][k])
          mask |= (1<<k);
      }
      int deg = d + prec[j][i];
      for(int k=max(__builtin_popcount(mask)-1, 0); k<K; k++){
        dp[mask][k] = umod(dp[mask][k] + pw[deg][k], MOD);
      }
    }
  }
  for(int i=0; i<K; i++){
    for(int mask=1; mask<(1<<K); mask++){
      if(((mask>>i)&1) == 0) continue;
      for(int k=0; k<K; k++){
        dp[mask][k] = umod(dp[mask^(1<<i)][k] + dp[mask][k], MOD);
      }
    }
  }
  scanf("%d", &q);
  while(q--){
    scanf("%s", t);
    int mask = 0, cnt = strlen(t);
    for(int i=0; i<cnt; i++){
      mask |= (1<<(t[i]-'a'));
    }
    printf("%d\n", dp[mask][cnt-1]);
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
