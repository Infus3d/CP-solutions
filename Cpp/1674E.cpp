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

int f(int a, int b){
  if(a*2 < b) return (b+1)/2;
  else return (a+b+2)/3;
}

void solve(){
  int n; scanf("%d", &n);
  vector<int> a(n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  int ans = (int)2e6;
  for(int i=0; i<n-1; i++){
    ans = min(ans, f(min(a[i], a[i+1]), max(a[i], a[i+1])));
  }
  for(int i=0; i<n-2; i++){
    ans = min(ans, min(a[i], a[i+2])+((max(a[i], a[i+2])-min(a[i], a[i+2])+1)/2));
  }
  sort(all(a));
  ans = min(ans, (a[0]+1)/2 + (a[1]+1)/2);
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
