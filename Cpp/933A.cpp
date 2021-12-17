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

const int N = 2e3+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, front[N][4], back[N][4], d[N];

void solve(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &d[i]);
  for(int i=1; i<=n; i++){
    int mx = 0;
    for(int j=1; j<3; j++){
      umax(mx, front[i-1][j]);
      front[i][j] = mx+(d[i] == j);
    }
  }
  for(int i=n; i>=1; i--){
    int mx = 0;
    for(int j=2; j>0; j--){
      umax(mx, back[i+1][j]);
      back[i][j] = mx+(d[i] == j);
    }
  }
  
  int ans = 0;
  for(int i=0; i<=n; i++){
    int f = max(front[i][1], front[i][2]);
    int b = max(back[i+1][1], back[i+1][2]);
    umax(ans, f+b);
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
