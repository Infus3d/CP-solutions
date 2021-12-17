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

const int N = 5e3+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int a, b, c, ans, C[N][N];

int mul(int x, int y){
  return (1LL * x * y) % MOD;
}

int add(int x, int y){
  return (0LL + x + y) % MOD;
}

int get(int x, int y){
  if(x > y) 
    swap(x, y);
  
  int ret = 0;
  for(int r=0; r<=x; r++){
    int f = 1;
    for(int i=y-r+1; i<=y; i++)
      f = mul(f, i);
    ret = add(ret, mul(f, C[x][r]));
  }
  
  return ret;
}

void solve(){
  scanf("%d%d%d", &a, &b, &c);
  
  C[0][0] = 1;
  for (int i = 1; i <= 5000; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = add(C[i-1][j-1], C[i-1][j]);
  }
  
  printf("%d\n", mul(get(a, b), mul(get(a, c), get(b, c))));
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
