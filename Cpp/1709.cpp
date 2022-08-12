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

int n, m, q;
int a[N], T[N<<2];

void build(int l, int r, int v){
  if(l == r){
    T[v] = a[l];
    return;
  }
  build(l, mid(l, r), v<<1);
  build(mid(l, r)+1, r, v<<1|1);
  T[v] = max(T[v<<1], T[v<<1|1]);
}

int get(int x, int y, int l, int r, int v){
  if(r < x || y < l)
    return 0;
  if(x <= l && r <= y)
    return T[v];
  return max(get(x, y, l, mid(l, r), v<<1), get(x, y, mid(l, r)+1, r, v<<1|1));
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=m; i++)
    scanf("%d", &a[i]);
  build(1, m, 1);
  
  scanf("%d", &q);
  while(q--){
    int xs, ys, xf, yf, k;
    scanf("%d%d%d%d%d", &xs, &ys, &xf, &yf, &k);
    if(abs(xf-xs) % k != 0 || abs(yf-ys) % k != 0){
      puts("NO");
      continue;
    }
    if(ys > yf)
      swap(ys, yf), swap(xs, xf);
    int maxh = get(ys, yf, 1, m, 1);
    int farthest = (n-xf)/k*k + xf;
    if(farthest <= maxh){
      puts("NO");
      continue;
    }
    puts("YES");
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
