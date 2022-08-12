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

int n, m;
int par[N];
int root1[N], root2[N], maxDepth1[N], maxDepth2[N];
vector<int> E[N], dsuParents;

int find(int x){
  if(par[x] == x)
    return x;
  return par[x] = find(par[x]);
}

void dfsFirst(int x, int y, int depth){
  if(umax(maxDepth1[find(x)], depth))
    root1[find(x)] = x;
  
  for(int i : E[x])
    if(i != y)
      dfsFirst(i, x, depth+1);
}

void dfsSecond(int x, int y, int depth){
  if(umax(maxDepth2[find(x)], depth))
    root2[find(x)] = x;
  
  for(int i : E[x])
    if(i != y)
      dfsSecond(i, x, depth+1);
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++) par[i] = i, maxDepth1[i] = maxDepth2[i] = -1;
  for(int i=1; i<=m; i++){
    int a, b; scanf("%d%d", &a, &b);
    a++; b++;
    E[a].push_back(b);
    E[b].push_back(a);
    if(find(a) != find(b))
      par[find(b)] = find(a);
  }
  
  for(int i=1; i<=n; i++)
    if(find(i) == i)
      dsuParents.push_back(i);
  
  for(int i=1; i<=n; i++){
    if(root1[find(i)] == 0){
      dfsFirst(i, 0, 0);
    }
  }
  
  for(int i=1; i<=n; i++){
    if(root2[find(i)] == 0){
      dfsSecond(root1[find(i)], 0, 0);
    }
  }
  
  vector<int> diameters;
  for(int i : dsuParents)
    diameters.push_back(maxDepth2[i]);
  sort(all(diameters));
  
  int ans = diameters.back();
  if(sz(dsuParents) == 1) printf("%d\n", ans);
  else if(sz(dsuParents) == 2){
    int a = diameters[0], b = diameters[1];
    umax(ans, (a/2 + a%2) + (b/2 + b%2) + 1);
    printf("%d\n", ans);
  }
  else{
    int a = diameters[sz(diameters)-2], b = diameters[sz(diameters)-1];
    umax(ans, (a/2 + a%2) + (b/2 + b%2) + 1);
    for(int i=0; i<sz(diameters)-2; i++){
      int cur = diameters[i];
      umax(ans, (a/2 + a%2) + (cur/2 + cur%2) + 2);
    }
    printf("%d\n", ans); 
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
