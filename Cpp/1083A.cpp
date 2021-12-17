#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define pll pair <ll, ll>
#define mid(x , y) ((x+y)>>1)
#define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 3e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

ll n, m, w[N], uke[N], seme[N];
vector<pll> E[N], v[N];

void dfsichi(ll x, ll y){
  for(pll i : E[x])
    if(i.ff ^ y){
      dfsichi(i.ff, x);
      umax(uke[x], uke[i.ff]-i.ss);
      v[x].pb(i);
    }
  uke[x] = max(0LL, uke[x]) + w[x];
  
  sort(all(v[x]), [&](const pll &x, const pll &y){
    return uke[x.ff]-x.ss >= uke[y.ff]-y.ss;
  });
}

void dfsni(ll x, ll y, ll val){
  seme[x] = val + w[x];
  //~ printf("x:%d, y:%d, val:%d, seme[x]:%d\n", x, y, val, seme[x]);
  pll oki = {-1, -1}, chisai = {-1, -1};
  if(sz(v[x]) >= 1) oki = v[x][0];
  if(sz(v[x]) >= 2) chisai = v[x][1];
  
  for(pll i : E[x])
    if(i.ff ^ y){
      ll cur = val;
      if(i != oki) umax(cur, max(0LL, uke[oki.ff]-oki.ss));
      else if(chisai.ff != -1) umax(cur, max(0LL, uke[chisai.ff]-chisai.ss));
      dfsni(i.ff, x, max(0LL, cur + w[x] - i.ss));
    }
}

void kaiketsu(){
  scanf("%lld", &n);
  for(ll i=1; i<=n; i++) scanf("%lld", &w[i]);
  for(ll i=1; i<n; i++){
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    E[a].pb({b, c});
    E[b].pb({a, c});
  }
  
  dfsichi(1, 0);
  dfsni(1, 0, 0);
  
  ll ans = 0;
  for(ll i=1; i<=n; i++)
    umax(ans, max(uke[i], seme[i]));
  printf("%lld\n", ans);
}

int main(){
  int tesutokesu = 1;
  //~ scanf("%d", &tesutokesu);
  while(tesutokesu--){
    kaiketsu();
  }
  return 0;
}
