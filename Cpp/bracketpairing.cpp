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

const int N = 21;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n;
char s[N], bracks[] = {'(', ')', '[', ']', '{', '}', '<', '>'};
map<vector<char>, ll> dp[N];

int getInd(char ch){
  for(int i=0; i<8; i++)
    if(bracks[i] == ch)
      return i;
  return -1;
}

ll rec(int x, vector<char> &v){
  if(sz(v) > n-x) return 0ll;
  if(x == n) return 1ll;
  if(dp[x].find(v) != dp[x].end())
    return dp[x][v];
  
  ll &ret = dp[x][v];
  ret = 0ll;
  if(s[x] == '?'){
    if(sz(v) > 0){
      char ch = v[sz(v)-1];
      v.pop_back();
      ret += rec(x+1, v);
      v.push_back(ch);
    }
    for(int i=0; i<8; i+=2){
      v.push_back(bracks[i]);
      ret += rec(x+1, v);
      v.pop_back();
    }
  }
  else{
    if(getInd(s[x]) % 2 == 1){
      if(sz(v) > 0 && getInd(s[x]) == getInd(v[sz(v)-1])+1){
        char ch = v[sz(v)-1];
        v.pop_back();
        ret += rec(x+1, v);
        v.push_back(ch);
      }
    }
    else{
      v.push_back(s[x]);
      ret += rec(x+1, v);
      v.pop_back();
    }
  }
  
  return ret;
}

void solve(){
  scanf("%s", s); n = strlen(s);
  vector<char> vec;
  printf("%lld\n", rec(0, vec));
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
