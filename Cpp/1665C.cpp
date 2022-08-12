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

vector<int> E[N];
int n, d[N];

void solve(){
  scanf("%d", &n);
  for(int i=0; i<=n; i++) d[i] = 0;
  for(int i=1; i<n; i++){
    int a; scanf("%d", &a);
    d[a]++;
  }
  d[0] = 1;
  
  int ans = 0, plusone = 0;
  sort(d, d+n+1);
  for(int i=n; i>=0; i--){
    if(d[i] == 0) break;
    ans++;
  }
  for(int i=n; i>=0; i--){
    d[i] = max(0, d[i]-ans);
    if(d[i] == 0) break;
    plusone = 0;
    ans += (d[i]+1)/2;
    plusone = d[i]%2;
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
