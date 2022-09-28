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
  vector<int> a(n);
  vector<int> even, odd;
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    if(a[i] % 2 == 1) odd.push_back(i+1);
    else even.push_back(i+1);
  }
  vector<pair<int, int>> ans;
  if(!sz(even) || !sz(odd)){
    for(int i=0; i<n-1; i++){
      ans.push_back({i+1, n});
    }
  } else {
    if(even[0] < odd[0]){
      for(int i=0; i<sz(even)-1; i++){
        ans.push_back({even[i], even.back()});
      }
      for(int i : odd){
        ans.push_back({even[0], i});
      }
    } else {
      for(int i=0; i<sz(odd)-1; i++){
        ans.push_back({odd[i], odd.back()});
      }
      for(int i : even){
        ans.push_back({odd[0], i});
      }
    }
  }
  printf("%d\n", sz(ans));
  for(auto i : ans){
    printf("%d %d\n", i.ff, i.ss);
  }
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
