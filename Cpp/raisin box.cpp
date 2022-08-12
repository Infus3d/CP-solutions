#include "bits/stdc++.h"
 #include "ext/pb_ds/assoc_container.hpp"

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
 using namespace __gnu_pbds;

const int N = 1e5+2;
const int M = 600;
const int MOD = 998244353;
const int K = 1e3+2;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
 typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, d[N], l[N], r[N], cnt;
int T[2][N<<2];
map<int, int> mk;

void upd(int t, int x, int val, int l, int r, int v){
  if(l == r){
    T[t][v] = val;
    return;
  }
  if(x <= mid(l, r))
    upd(t, x, val, l, mid(l, r), v<<1);
  else
    upd(t, x, val, mid(l, r)+1, r, v<<1|1);
  if(t == 1) T[t][v] = min(T[t][v<<1], T[t][v<<1|1]);
  else T[t][v] = max(T[t][v<<1], T[t][v<<1|1]);
}

int get(int t, int x, int y, int l, int r, int v){
  if(r < x || y < l)  return (t ? n+1 : 0);
  if(x <= l && r <= y) return T[t][v];
  int lef = get(t, x, y, l, mid(l, r), v<<1);
  int rig = get(t, x, y, mid(l, r)+1, r, v<<1|1);
  if(t == 1) return min(lef, rig);
  else return max(lef, rig);
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &d[i]), mk[d[i]] = 1;
  for(auto &i : mk) i.ss = ++cnt;
  for(int i=1; i<=n; i++){
    l[i] = i-get(0, mk[d[i]], cnt, 1, cnt, 1);
    upd(0, mk[d[i]], i, 1, cnt, 1);
  }
  for(int i=n; i>=1; i--) upd(1, mk[d[i]], n+1, 1, cnt, 1);
  for(int i=n; i>=1; i--){
    r[i] = get(1, mk[d[i]], cnt, 1, cnt, 1)-i;
    if(r[i] < 0) r[i] = n-i+1;
    upd(1, mk[d[i]], i, 1, cnt, 1);
  }
  for(int i=1; i<=n; i++){
    //~ printf("l[i]:%d, r[i]:%d\n", l[i], r[i]);
    printf("%lld ", 1LL * l[i] * r[i]);
  }
  puts("");
  return 0;
}
