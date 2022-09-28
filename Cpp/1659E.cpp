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
int a[N], b[N], c[N], par[N][30];

int find(int t, int x){
  if(par[x][t] == x)
    return x;
  return par[x][t] = find(t, par[x][t]);
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int j=0; j<30; j++){
    for(int i=1; i<=n; i++)
      par[i][j] = i;
  }
  for(int i=0; i<m; i++){
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    for(int j=0; j<30; j++){
      if(((c[i]>>j)&1) && find(j, a[i]) != find(j, b[i]))
        par[find(j, b[i])][j] = find(j, a[i]);
    }
  }
  vector<vector<bool>> singleClear(30, vector<bool>(n+1, false));
  vector<vector<bool>> doubleClear(30, vector<bool>(n+1, false));
  for(int i=0; i<m; i++){
    if((c[i] & 1)) continue;
    for(int j=1; j<30; j++){
      if((c[i]>>j)&1){
        singleClear[j][find(j, a[i])] = true;
        singleClear[j][find(j, b[i])] = true;
      }
      else{
        doubleClear[j][find(j, a[i])] = true;
        doubleClear[j][find(j, b[i])] = true;
      }
    }
  }
  
  scanf("%d", &q);
  while(q--){
    int u, v;
    scanf("%d%d", &u, &v);
    bool zeroPossible = false;
    for(int i=0; i<30; i++){
      if(find(i, u) == find(i, v)){
        zeroPossible = true;
        break;
      }
    }
    if(zeroPossible){
      puts("0");
      continue;
    }
    bool onePossible = false;
    for(int i=1; i<30; i++){
      if(singleClear[i][find(i, u)] || doubleClear[i][find(i, u)]){
        onePossible = true;
        break;
      }
    }
    if(onePossible){
      puts("1");
      continue;
    }
    puts("2");
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
