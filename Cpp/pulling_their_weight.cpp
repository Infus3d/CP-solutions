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
const int K = 2e4;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

void solve(){
  int n; scanf("%d", &n);
  vector<int> a(n+1), b(20002), c(20002);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    b[a[i]]++;
    c[a[i]]++;
  }
  for(int i=K; i>=1; i--) c[i] = c[i+1] + (c[i] * i);
  for(int i=1; i<=K; i++) b[i] = b[i-1] + (b[i] * i);
  for(int i=1; i<=K; i++)
    if(b[i-1] == c[i+1]){
      printf("%d\n", i);
      break;
    }
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
