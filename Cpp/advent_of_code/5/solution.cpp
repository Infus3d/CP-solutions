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

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

struct mpoint{
  int x1, x2, y1, y2;
};

int d[N][N];
int n, m;

void solve(){
  vector<mpoint> vall;
  int x1, x2, y1, y2;
  while(!feof(stdin) && scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2)){
    //~ printf("%d %d -> %d %d\n", x1, y1, x2, y2);
    vall.pb({x1, x2, y1, y2});
    umax(n, max(x1, x2));
    umax(m, max(y1, y2));
  }
  vall.pop_back();
  
  for(auto i : vall){
    int dx = (i.x1 == i.x2 ? 0 : (i.x1 < i.x2 ? 1 : -1));
    int dy = (i.y1 == i.y2 ? 0 : (i.y1 < i.y2 ? 1 : -1));
    int delta = max(abs(i.x1 - i.x2), abs(i.y1 - i.y2));
    for(int j=0; j<=delta; j++){
      d[i.x1][i.y1]++;
      i.x1 += dx;
      i.y1 += dy;
    }
  }
  
  int ans = 0;
  for(int i=0; i<=n; i++)
    for(int j=0; j<=m; j++)
      if(d[i][j] > 1)
        ans++;
  printf("%d\n", ans);
}

int main(){
  freopen("input.txt", "r", stdin);
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
