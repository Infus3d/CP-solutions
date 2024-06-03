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

int T[N<<2];

void upd(int x, int val, int l, int r, int v){
    if(l == r){
        T[v] = val;
        return;
    }
    if(x <= mid(l, r)){
        upd(x, val, l, mid(l, r), v<<1);
    } else {
        upd(x, val, mid(l, r)+1, r, v<<1|1);
    }
    T[v] = max(T[v<<1], T[v<<1|1]);
}

int getMax(int x, int y, int l, int r, int v){
    if(y < l || r < x) return 0;
    if(x <= l && r <= y) return T[v];
    return max(getMax(x, y, l, mid(l, r), v<<1), getMax(x, y, mid(l, r)+1, r, v<<1|1));
}

bool solve(){
  int n; scanf("%d", &n);
  vector<pair<int, int>> v(n);
  map<int, int> mk, ml, rain;
  int cntk = 0, cntl = 0;
  for(int i=0; i<n; i++){
      scanf("%d%d", &v[i].ff, &v[i].ss);
      mk[v[i].ff] = 1;
      rain[v[i].ff] = v[i].ss;
      ml[v[i].ff] = 1;
  }
  for(auto &i : mk){
      i.ss = ++cntk;
  }
  int m; scanf("%d", &m);
  vector<pair<int, int>> h(m);
  for(int i=0; i<m; i++){
      scanf("%d%d", &h[i].ff, &h[i].ss);
      ml[h[i].ff] = ml[h[i].ss] = 1;
  }
  if(n == 0 && m == 0){
      return false;
  }
  for(auto &i : ml){
      i.ss = ++cntl;
  }
  for(int i=0; i<n; i++){
      upd(ml[v[i].ff], v[i].ss, 1, cntl, 1);
  }
  for(int i=0; i<m; i++){
      auto [a, b] = h[i];
      int theMax = 0;
      if(ml[a]+1 <= ml[b]-1){
          theMax = getMax(ml[a]+1, ml[b]-1, 1, cntl, 1);
      }
      if((rain[b] != 0 && theMax >= rain[b]) || (rain[a] != 0 && theMax >= rain[a]) || (rain[b] != 0 && rain[a] != 0 && rain[b] > rain[a])){
          printf("false\n");
      } else if(rain[b] == 0 || rain[a] == 0 || b-a != mk[b]-mk[a]){
          printf("maybe\n");
      } else {
          printf("true\n");
      }
  }
  for(int i=0; i<n; i++){
      upd(ml[v[i].ff], 0, 1, cntl, 1);
  }
  puts("");
  return true;
}

int main(){
  // int testcase = 1;
  // scanf("%d", &testcase);
  while(true){
    if(solve() == false)
        break;
  }
  return 0;
}
