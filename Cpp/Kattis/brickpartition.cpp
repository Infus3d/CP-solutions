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

const int N = 1e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, d, m;
char s[N], c;
ll k[N], a, b;

void solve(){
  a = 0LL, b = 0LL, n = 0LL;
  scanf("%d", &m);
  for(int i=1; i<=m; i++){
    scanf("%d %c", &d, &c);
    if(i > 1 && s[n] == c)
      k[n] += d;
    else{
      k[++n] = d;
      s[n] = c;
    }
    
    if(c == 'W')  a += d;
    else b += d;
  }
  
  if(a == 0 || b == 0){
    printf("%lld\n", (a == 0LL ? b : a));
    return;
  }
  
  ll mx = __gcd(a, b);
  ll smola = a/mx;
  ll smolb = b/mx;
  
  ll cura = 0LL, curb = 0LL, ans = 0LL;
  for(int i=1; i<=n; i++){
    if(s[i] == 'W'){
      ll tempa = cura + k[i];
      if(curb > 0 && curb % smolb == 0){
        ll rat = curb / smolb;
        if(cura <= rat*smola && rat*smola <= tempa)
          ans++, curb = 0LL, cura = tempa - (rat * smola);
        else 
          cura = tempa;
      }
      else
        cura += k[i];
    }
    else{
      ll tempb = curb + k[i];
      if(cura > 0 && cura % smola == 0){
        ll rat = cura / smola;
        if(curb <= rat*smolb && rat*smolb <= tempb)
          ans++, cura = 0LL, curb = tempb - (rat * smolb);
        else
          curb = tempb;
      }
      else
        curb += k[i];
    }
  }
  
  assert(cura == 0LL && curb == 0LL);
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
