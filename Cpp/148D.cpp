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

int a, b;
double dp[N][N];

double rec(int x, int y){
  //~ printf("%d %d\n", x, y);
  if(x < 0 || y < 0) return 0.0;
  if(x && !y) return 1.0;
  if(!x) return 0.0;
  
  double &ret = dp[x][y];
  if(dp[x][y] != -1.0)
    return ret;
  
  ret = double(1.0*x/(x+y));
  if(x + y > 2)
    ret += double(1.0*y/(x+y)) * double(1.0*(y-1)/(x+y-1)) * (1.0*x/(x+y-2)*rec(x-1, y-2) + 1.0*(y-2)/(x+y-2)*rec(x, y-3));
  return ret;
}

void solve(){
  scanf("%d%d", &a, &b);
  
  for(int i=0; i<=a; i++)
    for(int j=0; j<=b; j++)
      dp[i][j] = -1.0;
  printf("%.9lf\n", rec(a, b));
}

int main(){
  int testcase = 1;
  while(testcase--){
    solve();
  }
  return 0;
}
