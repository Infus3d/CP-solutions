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
const int K = 1e7+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

char s[N];

void solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  vector<vector<int>> a(n, vector<int>(k, 0));
  map<vector<int>, int> cnt;
  for(int i=0; i<n; i++){
    for(int j=0; j<k; j++){
      scanf("%d", &a[i][j]);
      a[i][j]++;
    }
    map<vector<int>, int> vis;
    for(int j=0; j<i; j++){
      vector<int> third(k, 0);
      for(int u=0; u<k; u++){
        if(a[i][u] == a[j][u])
          third[u] = a[i][u];
        else
          third[u] = a[i][u] ^ a[j][u];
      }
      if(vis[third] > 0){
        cnt[third]++;
        cnt[a[i]]++;
        cnt[a[j]]++;
      }
      vis[a[j]]++;
    }
  }
  long long ans = 0;
  for(int i=0; i<n; i++){
    long long m = cnt[a[i]];
    ans += (m-1) * m / 2;
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
