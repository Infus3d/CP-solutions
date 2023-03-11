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

void sendRow(int rid, vector<vector<char>> &t){
  int n = sz(t), m = sz(t[0]);
  for(int j=0; j<=m; j++){
    if(j > 0 && (j == m || t[rid][j] == '#')){
      for(int i=rid; i<=n; i++){
        if(i > 0 && (i == n || t[i][j-1] == '#')){
          t[i-1][j-1] = '#';
          break;
        }
      }
      break;
    }
  }
}

vector<int> findSolution(vector<vector<char>> a){
  int n = sz(a);//, m = sz(a[0]);
  vector<vector<char>> b = a;
  vector<int> ans(2, 0);
  for(int i=0; i<n; i++){
    while(a[i][0] != '#'){
      sendRow(i, a);
      ans[0]++;
    }
  }
  // printf("After min\n");
  // for(int i=0; i<n; i++){
    // for(int j=0; j<m; j++){
      // printf("%c", a[i][j]);
    // }
    // puts("");
  // } 
  for(int i=n-1; i>=0; i--){
    while(b[i][0] != '#'){
      sendRow(i, b);
      ans[1]++;
    }
  }
  // printf("After max\n");
  // for(int i=0; i<n; i++){
    // for(int j=0; j<m; j++){
      // printf("%c", b[i][j]);
    // }
    // puts("");
  // }
  return ans;
}

char s[N];

void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<char>> vec(n, vector<char>(m));
  for(int i=0; i<n; i++){
    scanf("%s", s);
    for(int j=0; j<m; j++){
      vec[i][j] = s[j];
    }
  }
  vector<int> res = findSolution(vec);
  assert(sz(res) == 2);
  printf("Min: %d, Max: %d\n", res[0], res[1]);
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
