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

char s[N], t;

void solve(){
  int n; scanf("%d", &n);
  vector<int> a(n+1), b(n+1);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    b[a[i]] = i;
  }
  vector<int> d(n+1);
  for(int i=n; i>=1; i--){
    if(b[i] > i){
      puts("-1");
      return;
    }
    int shift = b[i]%i;
    for(int j=1; j<=i; j++){
      b[j] = (b[j] - shift + i) % i;
      if(b[j] == 0) b[j] = i;
    }
    d[i] = shift;
  }
  for(int i=1; i<=n; i++){
    printf("%d ", d[i]);
  }
  puts("");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
