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

int n, k;

void solve(){
  scanf("%d%d", &n, &k);
  int m = n-1;
  vector<int> vis(n, 0);
  if(n == 4){
    if(k == 0)
      puts("0 3\n1 2");
    else if(k == 1)
      puts("0 2\n1 3");
    else if(k == 2)
      puts("0 1\n2 3");
    else
      puts("-1");
    return;
  }
  else if(k == 1){
    printf("%d %d\n", m, 1);
    printf("%d %d\n", (m^1), 0);
    vis[m] = vis[1] = vis[m^1] = vis[0] = 1;
  }
  else if(k == m){
    printf("%d %d\n", m, m-1);
    printf("%d %d\n", 1, 3);
    printf("%d %d\n", m^3, 0);
    vis[m] = vis[m-1] = vis[1] = vis[3] = vis[m^3] = vis[0] = 1;
  }
  else if(k != 0){
    printf("%d %d\n", m, k);
    printf("%d %d\n", m^k, 0);
    vis[m] = vis[k] = vis[m^k] = vis[0] = 1;
  }
  for(int i=0; i<=m; i++)
    if(!vis[i]){
      printf("%d %d\n", i, m^i);
      assert((m^i) <= m);
      vis[i] = vis[m^i] = 1;
    }
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
