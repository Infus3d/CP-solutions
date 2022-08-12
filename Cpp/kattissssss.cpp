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

int dp[N][6], n;
char s[N];

bool vow(char c){
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
  if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
  return false;
}

int add(int &x, int y){
  return (x = (x+y)%MOD);
}

void solve(){
  scanf("%s", s);
  n = strlen(s);
  
  dp[0][0] = 1;
  for(int i=0; i<n; i++){
    for(int j=0; j<6; j++)
      add(dp[i][j], dp[i-1][j]);
    for(int j=1; j<6; j++){
      if(vow(s[i]) && j%2 == 0) continue;
      if(!vow(s[i]) && j%2 == 1) continue;
      add(dp[i][j], dp[i-1][j-1]);
    }
  }
  printf("%d\n", dp[n-1][5]);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
