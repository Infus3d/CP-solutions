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
  if(n == 4)
    printf("8\n");
  else{
    if(n > 4) n--;
    printf("%lld\n", (long long)(n+1)*(n+1) - (long long)n * n);
  }
  
  vector<pair<int, pair<int, int>>> v;
  for(int i=1; i<=100; i++){
    for(int j=1; j<i; j++){
      v.push_back({i*i - j*j, {j*j, i*i}});
    }
  }
  sort(all(v));
  for(auto i : v)
    printf("diff -> %d, j*j -> %d, i*i -> %d\n", i.ff, i.ss.ff, i.ss.ss);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
