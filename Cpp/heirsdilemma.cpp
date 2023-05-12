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
  int a, b;
  int ans = 0;
  scanf("%d%d", &a, &b);
  for(int i=a; i<=b; i++){
    vector<int> v;
    int x = i;
    while(x > 0){
      v.push_back(x % 10);
      x /= 10;
    }
    sort(all(v));
    bool ok = true;
    for(int k=0; k<sz(v); k++){
      int j = v[k];
      if(j == 0 || i % j != 0 || (k > 0 && v[k] == v[k-1])){
        ok = false;
      }
    }
    if(ok == true)
      ans++;
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
