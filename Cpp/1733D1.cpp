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
const int K = 5e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

char a[K], b[K];

void solve(){
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  scanf("%s%s", a, b);
  vector<int> v;
  for(int i=0; i<n; i++){
    if(a[i] != b[i])
      v.push_back(i);
  }
  if(sz(v) % 2 == 1){
    puts("-1");
    return;
  }
  if(sz(v) == 2 && v[0]+1 == v[1])
    printf("%d\n", min(x, y*2));
  else
    printf("%lld\n", 1LL * (sz(v)/2) * y);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
