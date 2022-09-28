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
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  int l = 1, r = (int)1e9+1;
  while(l + 1 < r){
    int m = mid(l, r);
    int cnt = 0;
    vector<int> b = a;
    for(int &i : b){
      if(i*2 < m){
        cnt++;
        i = (int)1e9;
      }
    }
    if(cnt > k){
      r = m;
      continue;
    }
    bool indiv = false;
    for(int i = 0; i < n; i++){
      if(b[i] >= m){
        indiv = true;
      }
    }
    bool pairs = false;
    for(int i = 0; i < n-1; i++){
      if(min(b[i], b[i+1]) >= m){
        pairs = true;
      }
    }
    if(!indiv) cnt++;
    if(pairs || cnt+1 <= k) l = m;
    else r = m;
  }
  printf("%d\n", l);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
