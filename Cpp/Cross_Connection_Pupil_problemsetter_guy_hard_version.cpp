#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

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
using namespace __gnu_pbds;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

void solve(){
  int n; scanf("%d", &n);
  vector<int> a(n), b(n), pos(n+1);
  for(int i=0; i<n; i++) scanf("%d", &a[i]);
  for(int i=0; i<n; i++) scanf("%d", &b[i]), pos[b[i]] = i;
  
  ll ans = 0LL;
  ordered_set setik;
  for(int i=0; i<n; i++){
    if(!setik.empty())
      ans += (setik.size() - setik.order_of_key(pos[a[i]]));
    setik.insert(pos[a[i]]);
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
