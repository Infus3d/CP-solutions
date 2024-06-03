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

int n, q, P[7], d[N];
int T[N<<2][7];
char s[N];

void combine(int v){
    for(int i=1; i<=6; i++){
        T[v][i] = T[v<<1][i] + T[v<<1|1][i];
    }
}

void build_tree(int l, int r, int v){
    if(l == r){
        T[v][s[l-1]-'0']++;
        return;
    }
    build_tree(l, mid(l, r), v<<1);
    build_tree(mid(l, r)+1, r, v<<1|1);
    combine(v);
}

void upd(int x, int val, int l, int r, int v){
    if(l == r){
        T[v][d[l]]--;
        d[l] = val;
        T[v][d[l]]++;
        return;
    }
    if(x <= mid(l, r)){
        upd(x, val, l, mid(l, r), v<<1);
    } else {
        upd(x, val, mid(l, r)+1, r, v<<1|1);
    }
    combine(v);
}

void get(int x, int y, vector<int> &acc, int l, int r, int v){
    if(y < l || r < x) return;
    if(x <= l && r <= y){
        for(int i=1; i<=6; i++){
            acc[i] += T[v][i];
        }
        return;
    }
    get(x, y, acc, l, mid(l, r), v<<1);
    get(x, y, acc, mid(l, r)+1, r, v<<1|1);
}

void solve(){
  scanf("%d%d", &n, &q);
  for(int i=1; i<=6; i++){
      scanf("%d", &P[i]);
  }
  scanf("%s", s);
  for(int i=0; i<n; i++){
      d[i+1] = s[i] - '0';
  }
  build_tree(1, n, 1);
  while(q--){
      int t, x, y;
      scanf("%d%d%d", &t, &x, &y);
      if(t == 1){
          upd(x, y, 1, n, 1);
      } else if(t == 2){
          P[x] = y;
      } else {
          vector<int> acc(7, 0);
          get(x, y, acc, 1, n, 1);
          long long ans = 0;
          for(int i=1; i<=6; i++){
              ans += 1LL * acc[i] * P[i];
          }
          printf("%lld\n", ans);
      }
  }
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
