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

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

map<int, int> mk;

void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n+1), b(n+1), c(n+2);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    b[i] = b[i-1] + a[i];
  }
  
  mk[0] = 1;
  for(int i=n; i>=1; i--){
    c[i] = c[i+1] + a[i];
    mk[c[i]] = 1;
  }
  
  while(m--){
    int q;
    scanf("%d", &q);
    bool ans = false;
    for(int i=0; i<=n; i++){
      if(i > 0)
        mk[c[i]] = 0;
      if(b[i] <= q && mk[q-b[i]] > 0)
        ans = true;
    }
    mk[0] = 1;
    for(int i=n; i>=1; i--)
      mk[c[i]] = 1;
    puts(ans ? "YES" : "NO");
  }
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
