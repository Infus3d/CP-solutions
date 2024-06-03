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
  vector<int> v(n);
  for(int i=0; i<n; i++){
      scanf("%d", &v[i]);
  }
  multiset<int> setik;
  vector<int> seen(n+2, 0);
  vector<int> ok(n+1, 0);
  for(int i=n-1; i>=0; i--){
      if(!seen[v[i]]){
          ok[i] = 1;
      }
      seen[v[i]] = 1;
  }
  for(int i=1; i<=n+1; i++){
      setik.insert(i);
  }
  for(int i=0; i<n; i++){
      if(setik.find(v[i]) != setik.end()){
          setik.erase(setik.find(v[i]));
      }
  }
  vector<int> ans;
  for(int i=0; i<n; i++){
      assert(!setik.empty());
      if(sz(setik) == 1 && *setik.begin() == n+1){
          puts("Error");
          return;
      }
      ans.push_back(*setik.begin());
      setik.erase(setik.begin());
      if(ok[i]) setik.insert(v[i]);
  }
  for(int i : ans){
      printf("%d\n", i);
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
