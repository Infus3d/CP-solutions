#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)  x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 1e2+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

void solve(){
  int n;
  scanf("%d", &n);
  vector<int> a(n, 0);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  sort(all(a));
  long long threat = a[n-1], strength = 0;
  int cutoff = n-1;
  for(int i=n-2; i>=0; i--){
    strength += a[i];
    if(strength >= threat){
      cutoff = i;
      threat += strength;
      strength = 0;
    }
  }
  printf("%d\n", n-cutoff);
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
