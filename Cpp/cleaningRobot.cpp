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
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<int> a(n), b(n);
  for(int i=0; i<k; i++){
    scanf("%d%d", &a[i], &b[i]);
  }
  sort(all(a));
  sort(all(b));
  int ans = max(n, m), prev = 0;
  for(int i=0; i<k; i++){
    if(a[i] - prev > 1){
      ans = min(ans, a[i]-prev);
    }
    prev = a[i];
  }
  if(n+1 - a.back() > 1){
    ans = min(ans, n+1 - a.back());
  }
  prev = 0;
  for(int i=0; i<k; i++){
    if(b[i] - prev > 1){
      ans = min(ans, b[i]-prev);
    }
    prev = b[i];
  }
  if(m+1 - b.back() > 1){
    ans = min(ans, m+1 - b.back());
  }
  printf("%d\n", ans-1);
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
