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
  vector<int> a(n+1), b(n+1), inda(n+1), indb(n+1);
  vector<int> visa(n+1), visb(n+1), cycles(n + 5);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    inda[a[i]] = i;
  }
  for(int i=1; i<=n; i++){
    scanf("%d", &b[i]);
    indb[b[i]] = i;
  }
  
  int l = 1, r = n;
  for(int i=1; i<=n; i++){
    int p = i, cnt = 0;
    while(p <= n && visa[p] == 0){
      visa[p] = 1;
      cnt++;
      p = inda[b[p]];
    }
    cycles[cnt]++;
  }
  
  ll ans = 0LL;
  while(cycles[2] > 0){
    ans += 2*(r-l);
    l++, r--;
    cycles[2]--;
  }
  
  for(int i=4; i<=n; i += 2){
    while(cycles[i] > 0){
      int rr = r;
      for(int j=1; j<=i; j++){
        ans += (j == i ? rr : r) - l;
        if(j % 2) r--;
        else l++;
      }
      cycles[i]--;
    }
  }
  for(int i=3; i<=n; i += 2){
    while(cycles[i] > 0){
      int rr = r;
      for(int j=1; j<=i-1; j++){
        ans += (j == i-1 ? rr : r) - l;
        if(j % 2) r--;
        else l++;
      }
      cycles[i]--;
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
