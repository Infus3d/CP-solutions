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

int n;
char s[N];
int dp[50004][65];

bool ok(int num, int saiz){
  int x = 0, y = saiz;
  while(x < y){
    if(((num>>x)&1) != ((num>>y)&1))
      return true;
    x++, y--;
  }
  return false;
}

void solve(){
  scanf("%d", &n);
  scanf("%s", s);
  if(n < 5){
    puts("POSSIBLE");
    return;
  }
  
  memset(dp, 0, sizeof(dp));
  vector<int> poss; poss.pb(0);
  for(int i=0; i<5; i++){
    vector<int> v;
    for(int j : poss){
      if(s[i] == '?')
        v.pb(j*2), v.pb(j*2+1);
      else
        v.pb(j*2+(s[i]-'0'));
    }
    poss = v;
  }
  
  for(int i : poss) 
    if(ok(i, 4))
      dp[4][i] = 1;
  
  for(int i=5; i<n; i++){
    for(int mask=0; mask<32; mask++){
      if(!ok(mask, 4)) continue;
      int nmask = (mask&((1<<4)-1))*2;
      if(s[i] != '?'){
        nmask += s[i]-'0';
        if(ok(mask*2+(s[i]-'0'), 5))
          dp[i][nmask] |= dp[i-1][mask];
      }
      else{
        if(ok(mask*2, 5))
          dp[i][nmask] |= dp[i-1][mask];
        if(ok(mask*2+1, 5))
          dp[i][nmask+1] |= dp[i-1][mask];
      }
    }
  }
  
  int ans = 0;
  for(int i=0; i<32; i++)
    if(ok(i, 4))
      ans |= dp[n-1][i];
  
  puts(ans ? "POSSIBLE" : "IMPOSSIBLE");
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
