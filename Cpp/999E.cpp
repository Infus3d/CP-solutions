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

const int N = 5e3+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int cnt[N], d[N];
bool reach[N][N];
vector<int> E[N];

void solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for(int i=0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    E[a].push_back(b);
  }
  queue<int> Q;
  for(int i=1; i<=n; i++){
    Q.push(i);
    reach[i][i] = true;
    while(!Q.empty()){
      int cur = Q.front();
      Q.pop();
      cnt[i]++;
      
      for(int j : E[cur])
        if(reach[i][j] == false){
          reach[i][j] = true;
          Q.push(j);
        }
    }
  }
  for(int i=1; i<=n; i++) d[i] = i;
  sort(d+1, d+n+1, [&](int x, int y){
    return cnt[x] > cnt[y];
  });
  
  int ans = 0;
  for(int i=1; i<=n; i++){
    if(reach[k][d[i]]) continue;
    ans++;
    reach[k][d[i]] = true;
    Q.push(d[i]);
    while(!Q.empty()){
      int cur = Q.front();
      Q.pop();
      for(int j : E[cur])
        if(reach[k][j] == false){
          reach[k][j] = true;
          Q.push(j);
        }
    }
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
