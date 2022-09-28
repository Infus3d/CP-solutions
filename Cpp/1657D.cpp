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
  int n, m, C;
  scanf("%d%d", &n, &C);
  vector<long long> v(C+1);
  for(int i=0; i<n; i++){
    int c, d, h;
    scanf("%d%d%d", &c, &d, &h);
    umax(v[c], (long long)d*h);
  }
  for(int i=1; i<=C; i++){
    int cnt = 0;
    for(int j=i; j<=C; j+=i){
      umax(v[j], v[i]*(++cnt));
    }
    umax(v[i], v[i-1]);
  }
  scanf("%d", &m);
  while(m--){
    long long D, H;
    scanf("%lld%lld", &D, &H);
    int idx = upper_bound(all(v), D*H) - v.begin();
    if(idx == C+1) idx = -1;
    printf("%d ", idx);
  }
  puts("");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
