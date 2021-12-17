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

int n, k, c;
int a[N], b[N], d[N];

void solve(){
  scanf("%d%d", &n, &k);
  for(int i=1; i<=n; i++)
    scanf("%d", &d[i]);
  for(int i=1; i<=n; i++)
    scanf("%d", &c);
  
  c = 0;
  sort(d+1, d+n+1);
  for(int i=1; i<=n; i++){
    while(c < n && d[c+1] <= d[i]+k){
      c++;
      a[c] = i;
    }
    b[i] = c;
  }
  
  for(int i=1; i<=n; i++){
    a[i] = i-a[i]+1;
    a[i] = max(a[i-1], a[i]);
  }
  for(int i=n; i>=1; i--){
    b[i] = b[i]-i+1;
    b[i] = max(b[i+1], b[i]);
  }
  
  int ans = 0;
  for(int i=0; i<=n; i++)
    umax(ans, a[i]+b[i+1]);
  printf("%d\n", ans);
  
  for(int i=0; i<=n+1; i++) a[i] = b[i] = 0;
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
