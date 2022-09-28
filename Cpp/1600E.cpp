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

int L[N], R[N], a[N];

int rec(int l, int r, int val){
  //~ printf("l->%d, r->%d, val->%d\n", l, r, val);
  if(l == r) return val < a[l];
  if(val >= max(a[l], a[r])) return false;
  if(val >= min(a[l], a[r])){
    if(val >= a[l]) return L[r] % 2;
    else return R[l] % 2;
  }
  if(a[l] < a[r]){
    //~ printf("%d %d\n", r, R[r]);
    if(L[r] % 2 == 1) return 1;
    return !rec(l+1, r, a[l]);
  }
  else{
    if(R[l] % 2 == 1) return 1;
    return !rec(l, r-1, a[r]);
  }
}

void solve(){
  int n; scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  for(int i=1; i<=n; i++){
    if(a[i] < a[i-1])
      L[i] = L[i-1] + 1;
    else
      L[i] = 1;
    //~ printf("%d ", L[i]);
  }
  //~ puts("");
  for(int i=n; i>=1; i--){
    if(a[i] < a[i+1])
      R[i] = R[i+1] + 1;
    else
      R[i] = 1;
    //~ printf("%d ", R[i]);
  }
  int ans = rec(1, n, -1);
  printf("%s\n", ans ? "Alice" : "Bob");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
