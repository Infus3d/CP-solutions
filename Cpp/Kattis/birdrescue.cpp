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
#define y0 your_name

using namespace std;

const int N = 2e6+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, q, c, d[N];
int x0, y0;
int x1, x2, y1, y2;

void solve(){
  scanf("%d%d", &n, &q);
  scanf("%d%d", &x0, &y0);
  for(int i=1; i<=n; i++){
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int amin, amax, bmin, bmax;
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);
    if(x1 <= x0 && x0 <= x2) amin = 0;
    else amin = min(abs(x0-x1), abs(x0-x2));
    if(y1 <= y0 && y0 <= y2) bmin = 0;
    else bmin = min(abs(y0-y1), abs(y0-y2));
    
    amax = max(abs(x0-x1), abs(x0-x2));
    bmax = max(abs(y0-y1), abs(y0-y2));
    
    //~ printf("***** %d %d %d %d\n", amin, amax, bmin, bmax);
    d[amin+bmin] += 1; d[amax+bmax+1] -= 1;
  }
  
  for(int i=1; i<=(int)2e6; i++) d[i] += d[i-1];
  
  while(q--){
    scanf("%d", &c);
    printf("%d\n", d[c]);
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
