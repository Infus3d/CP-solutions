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
const int K = 1e7;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int P[K+1], ans[K+1];

void solve(){
  int n; scanf("%d", &n);
  printf("%d\n", ans[n]-1);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int i=1; i<=K; i++){
    for(int j=i; j<=K; j+=i)
      P[j] += i;
  }
  for(int i=1; i<=K; i++){
    if(P[i] <= K && ans[P[i]] == 0){
      ans[P[i]] = i+1;
    }
  }
  while(testcase--){
    solve();
  }
  return 0;
}
