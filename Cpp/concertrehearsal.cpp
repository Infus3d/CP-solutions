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

const int N = 5e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, p, k, a[N], vis[N];
ll rehsum, sum, reh[N], lim, par[N], cycle;

int find(int idx){
  int cur = idx;
  for(int i=18; i>=0; i--){
    int r = cur + (1<<i), l = idx;
    if(r < idx+n && par[r] - par[l-1] <= lim)
      cur += (1<<i);
  }
  return (par[cur] - par[idx-1] > lim) ? -1 : cur;
}

void solve(){
  scanf("%d%d%d", &n, &p, &k);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    sum += a[i];
    par[i] = par[i+n] = a[i];
  }
  for(int i=1; i<=2*n; i++) par[i] += par[i-1];
  
  memset(vis, -1, sizeof(vis));
  vis[n] = 0;
  lim = p % sum;
  int endind = n, lastday = -1;
  for(int i=1; i<=n; i++){
    int lastendind = endind;
    endind = find(endind == n ? 1 : endind+1);
    reh[i] = p / sum + ((endind >= n) ? 1 : 0);
    if(endind == -1) endind = lastendind;
    if(endind > n) endind -= n;
    lastday = i;
    if(vis[endind] != -1){
      cycle = i - vis[endind];
      break;
    }
    vis[endind] = i;
  }
  
  for(int i=vis[endind]+1; i<=lastday; i++) rehsum += reh[i];
  ll ans = (1LL * k / cycle) * rehsum;
  for(int i=1; i<=(k%cycle); i++) ans += reh[i];
  //~ for(int i=1; i<=lastday; i++) printf("i:%d, reh[i]:%lld\n", i, reh[i]);
  //~ printf("cycle:%lld, lastday:%d, endind:%d, rehsum:%lld\n", cycle, lastday, endind, rehsum);
  printf("%lld\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
