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

void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  vector<set<int>> E(n+1);
  for(int i=0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    E[a].insert(b);
    E[b].insert(a);
  }
  vector<int> vis(n+1);
  set<int> edges;
  for(int i=1; i<=n; i++){
    edges.insert(i);
  }
  vector<int> ans;
  queue<int> Q;
  for(int i=1; i<=n; i++){
    if(vis[i] == 1 || edges.empty()) continue;
    assert(Q.empty());
    Q.push(i);
    edges.erase(i);
    int cnt = 0;
    while(!Q.empty()){
      int cur = Q.front();
      Q.pop();
      vis[cur] = 1;
      cnt++;
      auto it = edges.begin();
      while(it != edges.end()){
        int temp = *it;
        it++;
        if(E[cur].find(temp) == E[cur].end()){
          edges.erase(temp);
          Q.push(temp);
        }
      }
    }
    ans.push_back(cnt);    
  }
  printf("%d\n", sz(ans));
  sort(all(ans));
  for(int i : ans)
    printf("%d ", i);
  puts("");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
