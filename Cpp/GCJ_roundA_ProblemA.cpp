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
  char s[109];
  int n;
  scanf("%s", s+1); n = strlen(s+1);
  
  vector<char> ans, buff;
  for(int i=1; i<=n; i++){
    ans.pb(s[i]);
    buff.pb(s[i]);
    if(s[i] > s[i+1]) buff.clear();
    else if(s[i] < s[i+1]){
      for(char j : buff)
        ans.pb(j);
      buff.clear();
    }
  }
  for(char i : ans) printf("%c", i);
  puts("");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int i=1; i<=testcase; i++){
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
