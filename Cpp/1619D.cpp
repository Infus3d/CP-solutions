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

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

pii d[N], p[N];
int n, m, vis[N], cn[N];

int get(int x, int y){
  return (x*n) + y;
}

void solve(){
  scanf("%d%d", &m, &n);
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      int ind = get(i, j);
      scanf("%d", &d[ind].ff);
      d[ind].ss = ind;
      p[ind] = {i, j};
      vis[j] = 0;
    }
    cn[i] = 0;
  }
  
  int tot = 0, flag = 0;
  sort(d, d+(n*m));
  for(int i=n*m-1; i>=0; i--){
    pii cur = d[i];
    if(!vis[p[cur.ss].ss])
      tot++;
    
    if(m < n && tot >= n){
      printf("%d\n", cur.ff);
      return;
    }
    
    if(cn[p[cur.ss].ff] > 0) flag = 1;
    
    if(tot >= n && flag){
      printf("%d\n", cur.ff);
      return;
    }
    
    vis[p[cur.ss].ss] = 1;
    cn[p[cur.ss].ff]++;
  }
  
  puts("-1");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
