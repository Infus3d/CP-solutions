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
  vector<int> v[4];
  for(int i=0; i<3; i++){
    for(int j=0; j<4; j++){
      int a; scanf("%d", &a);
      v[j].pb(a);
    }
  }
  for(int i=0; i<4; i++) sort(all(v[i]));
  
  int sum = 0;
  vector<int> ans;
  for(int i=0; i<4; i++){
    int a = v[i][0];
    int b = (int)1e6 - sum;
    a = min(a, b);
    ans.pb(a);
    sum += a;
  }
  if(sum != (int)1e6) puts("IMPOSSIBLE");
  else{
    for(int i=0; i<4; i++)
      printf("%d ", ans[i]);
    puts("");
  }
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
