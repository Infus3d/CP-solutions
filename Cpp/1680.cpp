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

const int N = 2e5+5;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n;
char s[2][N];
int c[2][N];

void solve(){
  scanf("%d", &n);
  for(int i=0; i<2; i++)
    scanf("%s", s[i]);
  
  pii a[2];
  int b[] = {0, 0};
  for(int i=0; i<2; i++){
    a[i].ff = n, a[i].ss = -1;
    for(int j=0; j<n; j++){
      c[i][j] = 0;
      if(s[i][j] == '*' && a[i].ff == n)
        a[i].ff = j;
      if(s[i][j] == '*'){
        a[i].ss = j;
        b[i]++;
        c[i][j] = 1;
      }
      if(j > 0)
        c[i][j] += c[i][j-1];
    }
  }
  
  int l = min(a[0].ff, a[1].ff), r = max(a[0].ss, a[1].ss);
  if(!b[0] || !b[1]){
    printf("%d\n", r-l);
    return;
  }
  
  int x = r-l;
  if(c[1][a[0].ff] > 0) x++;
  if(c[1][n-1] - c[1][a[0].ss] > 0) x++;
  x += c[1][a[0].ss] - c[1][a[0].ff];
  
  int y = r-l;
  if(c[0][a[1].ff] > 0) y++;
  if(c[0][n-1] - c[0][a[1].ss] > 0) y++;
  y += c[0][a[1].ss] - c[0][a[1].ff];
  
  //~ printf("**** %d\n", c[1][a[0].ss] - c[1][a[0].ff]);
  //~ printf("jfaldjfjk %d %d, tot : %d\n", a[0].ss, a[0].ff, c[1][n-1]);
  //~ printf("%d %d\n", x, y);
  printf("%d\n", min(x, y));
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
