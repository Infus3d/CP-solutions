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

int n, m, flag = 0, cnt = 0;
vector<int> E[N];
int fup[N], tin[N];

void dfs(int x, int par){
    tin[x] = fup[x] = ++cnt;
    for(int i : E[x]){
        if(!tin[i]){
            dfs(i, x);
            // printf("x:%d, i:%d, tin[i]:%d, fup[i]:%d\n", x, i, tin[i], fup[i]);
            if(fup[i] > tin[x]){
                flag = true;
            }
        }
        if(i != par) {
            fup[x] = min(fup[x], fup[i]);
        }
    }
}

void solve(int _n, int _m){
  n = _n, m = _m;
  cnt = 0;
  flag = false;
  for(int i=0; i<n; i++){
      tin[i] = fup[i] = 0;
      E[i].clear();
  }
  for(int i=0; i<m; i++){
      int a, b;
      scanf("%d%d", &a, &b);
      E[a].push_back(b);
      E[b].push_back(a);
  }
  dfs(0, -1);
  if(m == 0 || cnt < n){
      puts("Yes");
      return;
  }
  printf("%s\n", flag ? "Yes" : "No");
}

int main(){
  // int testcase = 1;
  // scanf("%d", &testcase);
  while(true){
      int _n, _m;
      scanf("%d%d", &_n, &_m);
      if(!_n && !_m) break;
      solve(_n, _m);
  }
  return 0;
}
