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
const int K = 3e3+1;
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

void solve(){
  int n; scanf("%d", &n);
  vector<int> treex(K), treey(K);
  for(int i=0; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    treex[a]++, treey[b]++;
  }
  int m; scanf("%d", &m);
  vector<int> wellx(K), welly(K);
  for(int i=0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    wellx[a]++, welly[b]++;
  }
  int ans = 0;
  for(int i=0; i<K; i++){
    for(int j=0; j<K; j++){
      long long dist = ((i-j) * (i-j)) % MOD;
      long long cntx = (1LL * treex[i] * wellx[j]) % MOD;
      long long cnty = (1LL * treey[i] * welly[j]) % MOD;
      ans = (ans + ((dist * cntx) % MOD)) % MOD;
      ans = (ans + ((dist * cnty) % MOD)) % MOD;
    }
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int i=1; i<=testcase; i++){
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
