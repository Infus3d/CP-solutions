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

const int N = 5e3+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n;
char s[N];

void solve(){
  scanf("%s", s);
  n = strlen(s);
  int ans = 0;
  for(int i=0; i<n; i++){
    int score = 0, qmark = 0;
    for(int j=i; j<n; j++){
      if(s[j] == '(') score++;
      else if(s[j] == ')') score--;
      else qmark++;
      if(score < 0) break;
      if(score < qmark){
        qmark--;
        score++;
      }
      if((j-i+1)%2 == 0 && (qmark >= score))
        ans++;
    }
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
