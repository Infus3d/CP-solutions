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

const int N = 1e3+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

vector<int> E[N];
double speed[N];

struct node{
    int h;
    double tot;
    
    node(int _h, double _tot) : h(_h), tot(_tot) {}
    node() {}
    
    node operator -(const node &b) const {
        return node(h - b.h, tot - b.tot);
    }
    
    node operator +(const node &b) const {
        return node(h + b.h, tot + b.tot);
    }
    
    node& operator +=(const node &a) {
        h += a.h;
        tot += a.tot;
        return *this;
    }
    
    bool operator <(const node &a) const {
        if(h == a.h){
            return tot < a.tot;
        }
        return h < a.h;
    }
    
    bool operator >(const node &a) const {
        if(h == a.h){
            return tot > a.tot;
        }
        return h > a.h;
    }
} dp[N][2];

void dfs(int u){
    dp[u][0].h = dp[u][1].h = 0;
    dp[u][0].tot = dp[u][1].tot = 0.0;
    for(int v : E[u]){
        dfs(v);
        dp[u][0] = dp[u][0] + dp[v][1];
    }
    dp[u][1] = dp[u][0];
    for(int v : E[u]){
        dp[u][1] = max(dp[u][1], dp[u][0] - dp[v][1] + dp[v][0] + node(1, min(speed[u], speed[v])));
    }
}

void solve(){
  int n; scanf("%d", &n);
  map<string, int> mk;
  int cnt = 0, r = -1;
  double spd;
  char s[15], t[15];
  for(int i=0; i<n; i++){
      scanf("%s%lf%s", s, &spd, t);
      string ss(s), tt(t);
      if(mk[ss] == 0) mk[ss] = ++cnt;
      if(tt == "CEO"){
          r = mk[ss];
          speed[mk[ss]] = spd;
      } else {
          if(mk[tt] == 0) mk[tt] = ++cnt;
          auto [a, par] = make_pair(mk[ss], mk[tt]);
          speed[a] = spd;
          E[par].push_back(a);
      }
  }
  dfs(r);
  printf("%d %.6lf\n", dp[r][1].h, dp[r][1].tot / dp[r][1].h);
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
