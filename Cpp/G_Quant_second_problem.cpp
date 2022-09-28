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

int solution(vector<int> &V, vector<int> &A, vector<int> &B){
  int n = (int)V.size();
  int m = (int)A.size();
  vector<vector<int>> E(n);
  vector<int> deg(n);
  for(int i=0; i<m; i++){
    E[A[i]].push_back(B[i]);
    deg[B[i]]++;
  }
  vector<int> leaf;
  for(int i=0; i<n; i++){
    if(deg[i] == 0){
      leaf.push_back(i);
    }
  }
  if(leaf.empty()){
    return 0;
  }
  sort(all(leaf), [&](int x, int y){
    return V[x] > V[y];
  });
  int ans = max(0, V[leaf[0]]) + ((int)leaf.size() > 1 ? max(0, V[leaf[1]]) : 0);
  for(int i : leaf){
    for(int j : E[i]){
      if(deg[j] == 1){
        ans = max(ans, V[i] + V[j]);
      }
    }
  }
  return ans;
}

void solve(){
  int n, m; scanf("%d%d", &n, &m);
  vector<int> V(n);
  for(int i=0; i<n; i++){
    scanf("%d", &V[i]);
  }
  vector<int> a(m), b(m);
  for(int i=0; i<m; i++){
    scanf("%d", &a[i]);
  }
  for(int i=0; i<m; i++){
    scanf("%d", &b[i]);
  }
  printf("%d\n", solution(V, a, b));
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
