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
  vector<vector<int>> v(k);
  vector<int> a(n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    v[a[i]%k].push_back(a[i]);
  }
  long long ans = 0;
  for(int i=0; i<(int)v[0].size(); i+=2){
    if(i < (int)v[0].size()-1){
      ans += (v[0][i] + v[0][i+1]) / k;
    }
  }
  
  int l = 1, r = k-1;
  while(l <= r){
    if(l+r < k){
      l++;
      continue;
    }
    if(l == r){
      while((int)v[l].size() > 1){
        ans += (v[l].end()[-1] + v[l].end()[-2]) / k;
        v[l].pop_back();
        v[l].pop_back();
      }
      break;
    }
    while(!v[l].empty() && !v[r].empty()){
      ans += (v[l].back() + v[r].back()) / k;
      v[l].pop_back();
      v[r].pop_back();
    }
    if(v[l].empty()) l++;
    if(v[r].empty()) r--;
  }
  if((int)v[0].size() % 2 == 1){
    ans += v[0].back() / k;
  }
  for(int i=1; i<k; i++){
    for(int j : v[i]){
      ans += j / k;
    }
  }
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
