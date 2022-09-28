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

int solution(string &s, int k){
  int n = (int)s.length();
  vector<int> pali(n, -1);
  for(int i=0; i<n; i++){
    int l = i-1, r = i+1;
    if(k == 1) pali[i] = i;
    while(l >= 0 && r < n && s[l] == s[r]){
      if(r-l+1 >= k && (pali[r] == -1 || pali[r] < l))
        pali[r] = l;
      l--;
      r++;
    }
    l = i, r = i+1;
    while(l >= 0 && r < n && s[l] == s[r]){
      if(r-l+1 >= k && (pali[r] == -1 || pali[r] < l))
        pali[r] = l;
      l--;
      r++;
    }
  }
  vector<int> dp(n+1);
  for(int i=1; i<=n; i++){
    if(pali[i-1] != -1){
      dp[i] = dp[pali[i-1]] + 1;
    }
    dp[i] = max(dp[i], dp[i-1]);
  }
  return dp[n];
}

void solve(){
  string s; cin >> s;
  int k; cin >> k;
  printf("%d\n", solution(s, k));
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
