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

void solve(){
  int a, b, c, d, cnt = 0;
  char s[] = {'*', '+', '-', '/'};
  scanf("%d%d%d%d", &a, &b, &c, &d);
  for(int i=1; i<=4; i++)
    for(int j=1; j<=4; j++){
      int lef, rig;
      if(i == 1) lef = a*b;
      if(i == 2) lef = a+b;
      if(i == 3) lef = a-b;
      if(i == 4 && b == 0) continue;
      if(i == 4) lef = a/b;
      
      if(j == 1) rig = c*d;
      if(j == 2) rig = c+d;
      if(j == 3) rig = c-d;
      if(j == 4 && d == 0) continue;
      if(j == 4) rig = c/d;
      if(lef == rig) printf("%d %c %d = %d %c %d\n", a, s[i-1], b, c, s[j-1], d), cnt++;
    }
  if(cnt == 0) printf("problems ahead\n");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
