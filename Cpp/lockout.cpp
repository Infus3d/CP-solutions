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

void solve(){
  int n; scanf("%d", &n);
  vector<long long> a(n), t(n), p(n);
  long long total = 0;
  for(int i=0; i<n; i++){
      scanf("%lld", &a[i]);
      total += a[i];
  }
  for(int i=0; i<n; i++){
      scanf("%lld", &t[i]);
  }
  for(int i=0; i<n; i++){
      scanf("%lld", &p[i]);
  }
  
  if(a[p[0]-1] < total-a[p[0]-1]){
      printf("1\n");
      for(int i=1; i<n; i++){
          printf("%lld ", p[i]);
      }
      printf("%lld\n", p[0]);
  } else if(a[p[0]-1] > total-a[p[0]-1]){
      printf("0.5\n");
      for(int i=0; i<n; i++){
          printf("%lld ", p[i]);
      }
      puts("");
  } else {
      assert(n > 1);
      if(n == 2){
          printf("0.25\n");
          for(int i=0; i<n; i++){
              printf("%lld ", p[i]);
          }
          puts("");
      } else {
          printf("0.5\n");
          printf("%lld %lld %lld ", p[0], p[2], p[1]);
          for(int i=3; i<n; i++){
              printf("%lld ", p[i]);
          }
          puts("");
      }
  }
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
