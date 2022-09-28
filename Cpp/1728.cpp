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

const int N = 2e3+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int d[N][N], n;
char s[N];

int check(char a, char b){
  if(a == b) return 3;
  return (a < b ? 1 : 2);
}

int rec(int l, int r){
  assert((r-l+1) % 2 == 0);
  if(r-l+1 == 2) return s[l] == s[r] ? 3 : 1;
  if(d[l][r] != -1) return d[l][r];
  d[l][r] = 0;
  int rrmove = rec(l, r-2), rlmove = rec(l+1, r-1);
  int lrmove = rec(l+1, r-1), llmove = rec(l+2, r);
  if(rrmove == 3) rrmove = check(s[r], s[r-1]);
  if(rlmove == 3) rlmove = check(s[r], s[l]);
  if(lrmove == 3) lrmove = check(s[l], s[r]);
  if(llmove == 3) llmove = check(s[l], s[l+1]);
  
  int rmove = -1;
  if(rrmove == 2 || rlmove == 2) rmove = 2;
  else if(rrmove == 3 || rlmove == 3) rmove = 3;
  else rmove = 1;
  
  int lmove = -1;
  if(lrmove == 2 || llmove == 2) lmove = 2;
  else if(lrmove == 3 || llmove == 3) lmove = 3;
  else lmove = 1;
  
  if(lmove == 1 || rmove == 1) d[l][r] = 1;
  else if(lmove == 3 || rmove == 3) d[l][r] = 3;
  else d[l][r] = 2;
  
  return d[l][r];
}

void solve(){
  scanf("%s", s);
  n = strlen(s);
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      d[i][j] = -1;
  int res = rec(0, n-1);
  if(res == 1) puts("Alice");
  else if(res == 2) puts("Bob");
  else puts("Draw");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
