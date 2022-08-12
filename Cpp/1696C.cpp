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
  int n, m;
  scanf("%d%d", &n, &m);
  vector<pair<ll, ll>> a;
  for(int i=0; i<n; i++){
    int x; scanf("%d", &x);
    int xx = x;
    while(xx % m == 0) xx /= m;
    if(!a.size() || a.back().first != xx)
      a.push_back({xx, x/xx});
    else
      a.back().second += x/xx;
  }
  int k; scanf("%d", &k);
  vector<pair<ll, ll>> b;
  for(int i=0; i<k; i++){
    int x; scanf("%d", &x);
    int xx = x;
    while(xx % m == 0) xx /= m;
    if(!b.size() || b.back().first != xx)
      b.push_back({xx, x/xx});
    else
      b.back().second += x/xx;
  }
  if(a.size() != b.size()){
    puts("NO");
    return;
  }
  for(int i=0; i<(int)a.size(); i++){
    if(a[i].first != b[i].first || a[i].second != b[i].second){
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
