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

bool seen[K];

void solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> v(n);
  for(int i=0; i<n; i++){
      scanf("%d", &v[i]);
  }
  sort(all(v));
  memset(seen, 0, sizeof(seen));
  seen[1] = 1;
  vector<int> dp;
  dp.push_back(1);
  for(int i : v){
      vector<int> toadd;
      for(int j : dp){
          if(i*j <= k && !seen[i*j]){
              toadd.push_back(i*j);
              seen[i*j] = 1;
          }
      }
      for(int j : toadd){
          dp.push_back(j);
      }
  }
  int ans = *max_element(dp.begin(), dp.end());
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
