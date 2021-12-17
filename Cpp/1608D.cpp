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

const int N = 1e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, dp[N][2];
string s[N];

int add(int x, int y){
  return (0LL + x + y) % MOD;
}

void solve(){
  cin >> n;
  for(int i=1; i<=n; i++)
    cin >> s[i];
  
  if(s[1][1] == 'W' || s[1][1] == '?')  dp[1][0] = 1;
  if(s[1][1] == 'B' || s[1][1] == '?')  dp[1][1] = 1;
  
  for(int i=2; i<=n; i++){
    int a[] = {0, 0};
    a[0] = dp[i-1][1];
    a[1] = dp[i-1][0];
    
    int val = 0;
    if(s[i][0] == 'W' || s[i][0] == '?') val = add(val, a[0]);
    if(s[i][0] == 'B' || s[i][0] == '?') val = add(val, a[1]);
    
    if(s[i][1] == 'W' || s[i][1] == '?') dp[i][0] = val;
    if(s[i][1] == 'B' || s[i][1] == '?') dp[i][1] = val;
  }
  
  int a[] = {0, 0};
  a[0] = dp[n][1];
  a[1] = dp[n][0];
  
  int val = 0;
  if(s[1][0] == 'W' || s[1][0] == '?') val = add(val, a[0]);
  if(s[1][0] == 'B' || s[1][0] == '?') val = add(val, a[1]);
  
  cout << val << '\n';
  
  for(int i=0; i<=n; i++)
    dp[i][0] = dp[i][1] = 0;
}

int main(){
  ios::sync_with_stdio(false);
	cin.tie(0);
  int testcase = 1;
  //~ cin >> testcase;
  while(testcase--){
    solve();
  }
  return 0;
}
