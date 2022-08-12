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
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

struct mynode{
  int product;
  vector<int> prime;
  mynode(){
    prime.resize(6);
    product = 1;
  }
} T[N<<2];

char s[10];
int n, q, in[N], out[N], d[N], cnt;
vector<int> E[N];

int id[] = {0, 0, 0, 1, 0, 2, 0, 3, 0, 0, 0, 4, 0, 5};

int mul(int x, int y){
  return (1LL * x * y) % MOD;
}

vector<int> prime_factorization(int val){
  vector<int> fac(6, 0);
  int divisor = 2;
  while(val > 1){
    if(val % divisor == 0)
      fac[id[divisor]]++, val /= divisor;
    else
      divisor++;
  }
  return fac;
}

mynode process(mynode &u, mynode &v){
  mynode ret;
  ret.product = mul(u.product, v.product);
  for(int i=0; i<6; i++)
    ret.prime[i] = u.prime[i] + v.prime[i];
  return ret;
}

void upd(int x, int val, int l=1, int r=cnt, int v=1){
  if(l == r){
    mynode t;
    t.prime = prime_factorization(val);
    t.product = val;
    T[v] = process(T[v], t);
    return;
  }
  if(x <= mid(l, r))
    upd(x, val, l, mid(l, r), v<<1);
  else
    upd(x, val, mid(l, r)+1, r, v<<1|1);
  
  T[v] = process(T[v<<1], T[v<<1|1]);
}

mynode get(int x, int y, int l=1, int r=cnt, int v=1){
  if(r < x || y < l)  { mynode ret; return ret; }
  if(x <= l && r <= y)  return T[v];
  mynode lef = get(x, y, l, mid(l, r), v<<1);
  mynode rig = get(x, y, mid(l, r)+1, r, v<<1|1);
  return process(lef, rig);
}

void dfs(int x){
  in[x] = ++cnt;
  for(int i : E[x])
    dfs(i);
  out[x] = cnt;
}

void solve(){
  scanf("%d", &n);
  for(int i=1; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    a++, b++;
    E[a].pb(b);
  }
  dfs(1);
  
  for(int i=1; i<=n; i++){
    scanf("%d", &d[i]);
    upd(in[i], d[i]);
  }
  
  scanf("%d", &q);
  while(q--){
    int a, b;
    scanf("%s%d", s, &a); a++;
    if(s[0] == 'R'){
      mynode ans = get(in[a], out[a]);
      int div = 1;
      for(int i=0; i<6; i++)
        div = mul(div, ans.prime[i]+1);
      printf("%d %d\n", ans.product, div);
    }
    else{
      scanf("%d", &b);
      upd(in[a], b);
    }
  }
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
