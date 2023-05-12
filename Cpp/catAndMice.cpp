#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y) / 2.0)
#define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;
const double eps = 0.0001;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n;
double m;
vector<int> a, b, t;

#define sqr(x) ((x) * (x))

bool ok(double x){
  vector<vector<double>> dp((1<<n), vector<double>(n+1, -1));
  vector<double> mul(n+1, 1);
  for(int i=1; i<=n; i++){
    mul[i] = mul[i-1] * m;
  }
  dp[0][0] = 0;
  for(int mask=0; mask<(1<<n); mask++){
    int k = __builtin_popcount(mask);
    for(int i=0; i<n; i++){
      if((((mask == 0 && i == 0) || (mask>>i)&1)) && dp[mask][i] >= 0){
        for(int j=0; j<n; j++){
          if(!((mask>>j)&1)){
            int newmask = mask | (1<<j);
            double dist = sqrt(sqr(a[i] - a[j]) + sqr(b[i] - b[j]));
            if(k == 0) dist = sqrt(sqr(a[j]) + sqr(b[j]));
            double curvel = x * mul[k];
            double newdp = dp[mask][i] + (dist / curvel);
            // printf("mask:%d, i:%d, j:%d, dist:%lf, curvel:%lf, dp[mask][i]:%lf, newdp:%lf\n", mask, i, j, dist, curvel, dp[mask][i], newdp);
            if(newdp <= t[j] || abs(t[j] - newdp) < eps){
              if(dp[newmask][j] < 0 || dp[newmask][j] > newdp){
                dp[newmask][j] = newdp;
              }
            }
          }
        }
      }
    }
  }
  for(int i=0; i<n; i++){
    if(dp[(1<<n)-1][i] >= 0){
      return true;
    }
  }
  return false;
}

void solve(){
  scanf("%d", &n);
  a.resize(n);
  b.resize(n);
  t.resize(n);
  for(int i=0; i<n; i++){
    scanf("%d%d%d", &a[i], &b[i], &t[i]);
  }
  scanf("%lf", &m);
  double l = 0, r = 300000;
  while((r-l) > eps){
    if(ok(mid(l, r)))
      r = mid(l, r);
    else
      l = mid(l, r);
  }
  printf("%.6lf\n", mid(l, r));
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
