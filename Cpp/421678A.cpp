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
  scanf("%s", s);
  int n = strlen(s);
  int a = -1, b = -1;
  for(int i=0; i<n; i++){
    if(s[i] == '1')
      a = i;
  }
  for(int i=n-1; i>=0; i--){
    if(s[i] == '0')
      b = i;
  }
  if(a == -1 && b == -1) printf("%d\n", n);
  else if(a == -1) printf("%d\n", b+1);
  else if(b == -1) printf("%d\n", n-a);
  else printf("%d\n", b-a+1);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
