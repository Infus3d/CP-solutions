#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define db puts("*****")
#define mid(x , y) ((x+y)>>1)
#define ff first
#define ss second
#define all(x)	x.begin(),x.end()
#define ll long long
#define sqr(x)	((x)*(x))
#define pii pair <int , int>
#define pll pair <ll, ll>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 your_name_engraved_herein

using namespace std;
// using namespace __gnu_pbds;

const int N = 2e5+2;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, P, Q, tot;
int f[N], d[N], unknown[N], smaller[N], seen[N], rest[N];
int T[N<<2];

int mul(int x, int y){
  return (1LL * x * y) % MOD;
}

int add(int x, int y){
  return (x + y) % MOD;
}

int bmod(int x, int y){
  if(!y) return 1;
  ll tr = bmod(x, y/2);
  tr = (tr * tr) % MOD;
  if(y&1) tr = (1LL * tr * x) % MOD;
  return (int)tr;
}

void upd(int x, int l, int r, int v){
  if(l == r){
    T[v]++;
    return;
  }
  
  if(x <= mid(l, r))
    upd(x, l, mid(l, r), v<<1);
  else
    upd(x, mid(l, r)+1, r, v<<1|1);
  
  T[v] = T[v<<1] + T[v<<1|1];
}

int get(int x, int y, int l, int r, int v){
  if(y < l || r < x)
    return 0;
  
  if(x <= l && r <= y)
    return T[v];
  
  return get(x, y, l, mid(l, r), v<<1) + get(x, y, mid(l, r)+1, r, v<<1|1);
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &d[i]);
    if(d[i] == -1)
      unknown[i]++;
    else
      seen[d[i]] = 1;
    unknown[i] += unknown[i-1];
  }
  for(int i=1; i<=n; i++){
    if(!seen[i]){
      rest[++tot] = i;
      smaller[i]++;
    }
    smaller[i] += smaller[i-1];
  }
  
  f[0] = 1;
  for(int i=1; i<=n; i++)
    f[i] = mul(f[i-1], i);
  
  int smallerSoFar = 0;
  for(int i=1; i<=n; i++){
    if(~d[i]){
      int temp = get(d[i]+1, n, 1, n, 1);
      temp = mul(temp, f[tot]);
      P = add(P, temp);
      
      if(tot >= 1){
        temp = tot - int(lower_bound(rest+1, rest+tot+1, d[i]) - rest) + 1;
        //~ printf("temp:%d, d[i]:%d\n", temp, d[i]);
        temp = mul(f[tot-1], mul(temp, unknown[i]));
        P = add(P, temp);
      }
      
      upd(d[i], 1, n, 1);
      smallerSoFar = add(smallerSoFar, smaller[d[i]]);
    }
    else{
      int temp = mul(smallerSoFar, f[tot-1]);
      P = add(P, temp);
      
      if(tot >= 2){
        temp = ((1LL * tot * (tot-1)) / 2LL) % MOD;
        temp = mul(f[tot-2], mul(temp, unknown[i-1]));
        P = add(P, temp);
      }
    }
  }
  
  Q = bmod(f[tot], MOD-2);
  P = mul(P, Q);
  
  printf("%d\n", P);
  
  return 0;
}
