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

const int N = 1e3+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

char s[N][N];
int n, m;
int dx[] = {-1, 0, +1, 0};
int dy[] = {0, -1, 0, +1};

bool ok(int x, int y){
  return 0 <= x && x < n && 0 <= y && y < m;
}

void solve(){
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++){
    scanf("%s", s[i]);
  }
  int ans = 0, mini = 3;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      ans += s[i][j] - '0';
      for(int k=0; k<4; k++){
        int x1 = i+dx[k];
        int y1 = j+dy[k];
        int x2 = i+dx[(k+1)%4];
        int y2 = j+dy[(k+1)%4];
        if(ok(x1, y1) && ok(x2, y2)){
          int sum1 = s[x1][y1]-'0';
          int sum2 = s[x2][y2]-'0';
          int sum3 = s[i][j]-'0';
          mini = min(mini, sum1+sum2+sum3);
        }
      }
    }
  }
  if(mini != 0) mini--;
  printf("%d\n", ans-mini);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
