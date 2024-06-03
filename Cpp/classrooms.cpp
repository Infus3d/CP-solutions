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
  vector<pair<int, int>> v(n);
  for(int i=0; i<n; i++){
      scanf("%d%d", &v[i].ss, &v[i].ff);
  }
  sort(all(v));
  multiset<int> setik;
  for(int i=0; i<k; i++){
      setik.insert(0);
  }
  int ans = 0;
  for(int i=0; i<n; i++){
      auto [b, a] = v[i];
      auto it = setik.lower_bound(a);
      if(it != setik.begin()){
          ans++;
          setik.erase(--it);
          setik.insert(b);
      }
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
