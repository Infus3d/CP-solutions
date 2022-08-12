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

ll a, b, pw[15][15];
vector<int> dig[2];
vector<ll> num[2];
unordered_map<ll, ll> mk[15];

ll rec(int t, int pos, ll mask, int eq){
  //~ printf("t:%d, sz(dig[t]):%d, pos:%d, mask:%lld, eq:%d, prod:%lld, sum:%lld\n", t, sz(dig[t]), pos, mask, eq, prod, sum);
  //~ for(int i=0; i<10; i++)
    //~ printf("%d ---> cnt:%d\n", i, v[i]);
  if(pos == sz(dig[t])){
    ll prod = 1, sum = 0LL;
    ll temp = mask;
    for(int i=0; i<10; i++){
      prod *= pw[i][(temp%14)];
      sum += (temp%14)*i;
      temp /= 14;
    }
    return ((sum > 0 && prod % sum == 0) ? 1 : 0);
  }
  if(mk[pos].find(mask) != mk[pos].end())
    return mk[pos][mask];
  
  mk[pos][mask] = 0;
  for(int i=0; i<10; i++){
    if(eq && i > dig[t][pos]) continue;
    if(i == 0 && mask != 0){
      if(eq && dig[t][pos] == 0){
        int p = num[t][pos];
        //~ for(int j=pos+1; j<sz(dig[t]); j++)
          //~ p = p*10 + dig[t][j];
        mk[pos][mask] += p+1;
      }
      else
        mk[pos][mask] += pw[10][sz(dig[t])-pos-1];
      continue;
    }
    ll nmask = mask + ((i == 0 && mask == 0) ? 0 : pw[14][i]);
    
    mk[pos][mask] += rec(t, pos+1, nmask, (eq && i == dig[t][pos]) ? 1 : 0);
  }
  //~ printf("%lld\n", mk[pos][eq][mask]);
  return mk[pos][mask];
}

void solve(){
  scanf("%lld%lld", &a, &b); a--;
  dig[0].clear(); dig[1].clear();
  num[0].clear(); num[1].clear();
  
  ll ai = a, bi = b;
  while(ai > 0) dig[0].pb(ai%10), ai /= 10;
  while(bi > 0) dig[1].pb(bi%10), bi /= 10;
  
  reverse(all(dig[0])); reverse(all(dig[1]));
  
  for(int j=0; j<=14; j++){
    pw[j][0] = 1LL;
    for(int i=1; i<=14; i++) pw[j][i] = pw[j][i-1]*j;
  }
  
  for(int j=0; j<sz(dig[0]); j++)
    num[0].pb(a%pw[10][j]);
  for(int j=0; j<sz(dig[1]); j++)
    num[1].pb(b%pw[10][j]);
    
  reverse(all(num[1])); reverse(all(num[0]));
  
  for(int i=0; i<15; i++) mk[i].clear();
  ll retb = rec(1, 0, 0LL, 1);
  for(int i=0; i<15; i++) mk[i].clear();
  ll reta = rec(0, 0, 0LL, 1);
  
  printf("%lld\n", retb-reta);
  //~ printf("retb:%lld, reta:%lld\n", retb, reta);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int tt=1; tt<=testcase; tt++){
    printf("Case #%d: ", tt);
    solve();
  }
  return 0;
}
