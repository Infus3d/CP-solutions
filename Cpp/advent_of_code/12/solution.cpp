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

map<string, int> id;
int vis[50], small[50], n, st, en, ans;
vector<int> E[N];
string s;

void dfs(int x, int v){
  if(x == en){
    ans++;
    return;
  }
  vis[x]++;
  for(int i : E[x]){
    if(vis[i] < 1)
      dfs(i, v);
    else if(!small[i])
      dfs(i, v);
    else if(vis[i] < 2 && v < 1 && i != st && i != en)
      dfs(i, v+1);
  }
  vis[x]--;
}

void solve(){
  freopen("input.txt", "r", stdin);
  //~ freopen("input2.txt", "r", stdin);
  while(cin >> s){
    int p = 0;
    string a = "", b = "";
    for(int i=0; s[i] != '-'; i++)
      a += s[i], p++;
    for(int i=p+1; i<(int)s.length(); i++)
      b += s[i];
    
    if(id.find(a) == id.end())
      id[a] = ++n;
    if(id.find(b) == id.end())
      id[b] = ++n;
    
    if(a == "start") st = id[a];
    if(a == "end") en = id[a];
    if(b == "start") st = id[b];
    if(b == "end") en = id[b];
    
    if(a[0] >= 'a') small[id[a]] = 1;
    if(b[0] >= 'a') small[id[b]] = 1;
    
    E[id[a]].pb(id[b]);
    E[id[b]].pb(id[a]);
  }
  
  memset(vis, 0, sizeof(vis));
  dfs(st, 0);
  
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
