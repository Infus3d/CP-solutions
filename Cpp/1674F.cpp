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

char s[N];
int fen[N][N], a[N][N];
int n, m, q;

void upd(int x, int y, int val){ //just adding val to [x, y] in 2D BIT
  while(x <= n){
    int y1 = y;
    while(y1 <= m){
      fen[x][y1] += val;
      y1 += (y1 & -y1);
    }
    x += (x & -x);
  }
}

int sum(int x, int y){ //getting the sum of the rect [1, 1, x, y]
  int ret = 0;
  while(x > 0){
    int y1 = y;
    while(y1 > 0){
      ret += fen[x][y1];
      y1 -= (y1 & -y1);
    }
    x -= (x & -x);
  }
  return ret;
}

int sumOfRect(int x1, int y1, int x2, int y2){
  int a = sum(x2, y2);
  int b = sum(x2, y1-1);
  int c = sum(x1-1, y2);
  int d = sum(x1-1, y1-1);
  
  return a - b - c + d; //2-dimensional partial/prefix sum
}

void solve(){
  scanf("%d%d%d", &n, &m, &q);
  int tot = 0;
  for(int i=1; i<=n; i++){
    scanf("%s", s);
    for(int j=1; j<=m; j++){
      if(s[j-1] == '*'){
        a[i][j] = 1;
        upd(i, j, 1);
        tot++;
      }
    }
  }
  while(q--){
    int x, y;
    scanf("%d%d", &x, &y);
    upd(x, y, -a[x][y] + (a[x][y]^1));
    tot += -a[x][y] + (a[x][y]^1);
    a[x][y] ^= 1;
    int col = tot / n;
    int good = sum(n, col);
    if(tot % n > 0){
      good += sumOfRect(1, col+1, tot%n, col+1);
    }
    printf("%d\n", tot - good);
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
