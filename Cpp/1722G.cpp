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
  int n; scanf("%d", &n);
  int exort = 0;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  map<int, bool> vis;
  for(int i=1; i<n; i++){
    while(true){
      int newrandom = (unsigned)rng() % (1<<31);
      if(vis[newrandom] || (i == n-2 && (exort^newrandom) == 0)) continue;
      vis[newrandom] = 1;
      printf("%d ", newrandom);
      exort ^= newrandom;
      break;
    }
  }
  printf("%d\n", exort);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
