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
  string t; 
  cin >> t;
  int m = t.length();
  vector<vector<int>> a(m+1);
  
  int n; cin >> n;
  string s[10];
  for(int i=0; i<n; i++){
    cin >> s[i];
    int k = s[i].length();
    for(int j=0; j<=m-k; j++)
      if(t.substr(j, k) == s[i])
        a[j].push_back(i);
  }
  
  vector<int> vis(m+1, -1), las(m+1), prev(m+1);
  vis[0] = 0;
  for(int i=0; i<m; i++){
    for(int k : a[i]){
      int j = s[k].length();
      int mini = -1, idx = -1;
      for(int u=i; u<min(m, i+j); u++)
        if(vis[u] != -1 && (mini == -1 || mini > vis[u]))
          mini = vis[u], idx = u;
          
      if(i+j <= m && mini != -1 && (vis[i+j] == -1 || vis[i+j] > mini+1))
        vis[i+j] = mini+1, las[i+j] = k, prev[i+j] = idx;
    }
  }
  
  printf("%d\n", vis[m]);
  if(vis[m] == -1) return;
  
  int p = m;
  while(p > 0){
    printf("%d %d\n", las[p]+1, p-int(s[las[p]].length())+1);
    p = prev[p];
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int testcase = 1;
  cin>>testcase;
  while(testcase--){
    solve();
  }
  return 0;
}
