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

char s[N];

void solve(){
  int n; scanf("%d", &n);
  scanf("%s", s);
  int cnt = 0, ans = 0;
  for(int i=0; i<n; i++){
    cnt++;
    if(i == n-1 || s[i] != s[i+1]){
      if(cnt % 2 == 1) ans++, cnt = 1;
      else cnt = 0;
    }
  }
  
  int lastBit = -1, minn = 0;
  for(int i=0; i<n; i+=2)
    if(s[i] == s[i+1]){
      minn += (s[i] != lastBit);
      lastBit = s[i];
    }
  printf("%d %d\n", ans, max(minn, 1));
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
