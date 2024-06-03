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

int switchBits(int x, int i){
    return x ^ (1 << i);
}

int switchBits(int x, int i, int j){
    return x ^ (1 << i) ^ (1 << j);
}

void solve(){
  vector<pair<int, int>> v;
  vector<int> orig;
  int a, cnt = 0;
  while(true){
      scanf("%d", &a);
      if(a == -1) break;
      v.push_back({a, cnt++});
      orig.push_back(a);
  }
  sort(all(v));
  reverse(all(v));
  vector<int> seen((int)(2<<18)+1, 0);
  vector<int> ans(sz(v), 0);
  for(auto [cur, idx] : v){
      for(int i=0; i<18; i++){
          ans[idx] += seen[switchBits(cur, i)];
          for(int j=i+1; j<18; j++){
              ans[idx] += seen[switchBits(cur, i, j)];
          }
      }
      seen[cur]++;
  }
  for(int i=0; i<sz(ans); i++){
      printf("%d:%d\n", orig[i], ans[i]);
  }
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
