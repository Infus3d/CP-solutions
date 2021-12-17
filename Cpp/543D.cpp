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
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, priori[N], responsum[N], a;
vector<int> E[N];

int mul(int x, int y){
  return (1LL * x * y) % MOD;
}

void dfsPrimis(int x, int par){
  priori[x] = 1;
  for(int i : E[x])
    if(i != par){
      dfsPrimis(i, x);
      priori[x] = mul(priori[x], priori[i]+1);
    }
}

void dfsSecundo(int x, int par, int val){
  responsum[x] = mul(priori[x], val);
  if(sz(E[x]) == 1 && x > 1) return;
  
  vector<int> front(sz(E[x])-(x > 1), 1);
  for(int i=0, j=0; i<sz(E[x]); i++)
    if(E[x][i] != par){
      front[j] = mul((j > 0 ? front[j-1] : 1), priori[E[x][i]]+1);
      j++;
    }
  
  vector<int> retro(sz(E[x])-(x > 1), 1);
  for(int i=sz(E[x])-1, j=sz(retro)-1; i>=0; i--)
    if(E[x][i] != par){
      retro[j] = mul((j < sz(retro)-1 ? retro[j+1] : 1), priori[E[x][i]]+1);
      j--;
    }
  
  int p = 0;
  for(int i : E[x])
    if(i != par){
      int nVal = val;
      if(p > 0) nVal = mul(nVal, front[p-1]);
      if(p < sz(retro)-1) nVal = mul(nVal, retro[p+1]);
      dfsSecundo(i, x, nVal+1);
      p++;
    }
}

void solve(){
  scanf("%d", &n);
  for(int i=2; i<=n; i++){
    scanf("%d", &a);
    E[a].pb(i);
    E[i].pb(a);
  }
  
  dfsPrimis(1, 0);
  dfsSecundo(1, 0, 1);
  
  for(int i=1; i<=n; i++)
    printf("%d ", responsum[i]);
  puts("");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
