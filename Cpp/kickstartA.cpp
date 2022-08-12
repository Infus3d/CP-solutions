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

char s[N], t[N];

void solve(){
  scanf("%s%s", s, t);
  int n = strlen(s), m = strlen(t);
  
  int p = 0;
  for(int i=0; i<n; i++){
    if(p == m){
      puts("IMPOSSIBLE");
      return;
    }
    while(p < m && t[p] != s[i]) p++;
    if(p == m){
      puts("IMPOSSIBLE");
      return;
    }
    p++;
  }
  printf("%d\n", m-n);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int tt=1; tt<=testcase; tt++){
    printf("Case #%d: ", tt);
    solve();
  }
  return 0;
}
