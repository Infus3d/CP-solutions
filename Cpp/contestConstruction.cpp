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

const int N = 52;
const int K = 19;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

ll dp[K][N][N];

void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  sort(all(a));
  long long ans = 0LL;
  for(int pos=1; pos<n; pos++){
    for(int i=pos-1; i>=0; i--){
      dp[2][pos][i] = 1LL;
    }
    if(pos > 1){
      for(int k=3; k<=m; k++){
        for(int i=pos-1; i>=0; i--){
          for(int j=i-1; j>=0; j--){
            if(a[pos] <= a[i] + a[j]){
              dp[k][pos][i] += dp[k-1][i][j];
            }
          }
        }
      }
    }
    if(pos >= m-1){
      for(int i=pos-1; i>=0; i--){
        ans += dp[m][pos][i];
      }
    }
  }
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
