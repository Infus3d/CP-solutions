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

string s, t;
vector<int> v[1002], vv[1002];
int n, k, m;

void update(int x, int y){
  int cur = 0;
  for(int dx=x-1; dx<=x+1; dx++)
    for(int dy=y-1; dy<=y+1; dy++){
      if(dx >= 0 && dx < n && dy >= 0 && dy < m){
        cur = cur*2 + v[dx][dy];
      }
      else{
        vv[x][y] = 0;
        return;
      }
    }
  
  printf("cur:%d\n", cur);
  vv[x][y] = (t[cur] == '#' ? 1 : 0);
}

void solve(){
  freopen("input.txt", "r", stdin);
  //~ freopen("input2.txt", "r", stdin);
  k = 10, n = k;
  cin >> t;
  
  for(int i=0; i<k; i++)
    for(int j=0; j<500; j++)
      v[i].pb(0);
  
  while(cin >> s){
    m = (int)s.length();
    if(sz(v[0]) == 0){
      
    }
    for(int i=0; i<k; i++)
      v[n].pb(0);
    for(int i=0; i<m; i++)
      v[n].pb(s[i] == '#' ? 1 : 0);
    for(int i=0; i<k; i++)
      v[n].pb(0);
    n++;
  }
  
  for(int i=n; i<n+k; i++)
    for(int j=0; j<m+2*k; j++)
      v[i].pb(0);
  
  db;
  printf("%d %d\n", n, m);
  for(int i=0; i<n+k; i++){
    for(int j=0; j<m+2*k; j++)
      printf("%d", v[i][j]);
    puts("");
  }
  
  n += k; m += 2*k;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      vv[i].pb(0);
  
  for(int step=0; step<2; step++){
    printf("step:%d\n", step);
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        update(i, j);
    
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        v[i][j] = vv[i][j], vv[i][j] = 0;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      printf("%d", v[i][j]);
    puts("");
  }
  
  int ans = 0;
  for(int i=1; i<n-1; i++){
    for(int j=1; j<m-1; j++){
      ans += v[i][j];
    }
  }
  printf("%d\n", ans);
  printf("%d %d\n", n, m);
  printf("tsize:%d\n", (int)t.length());
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
