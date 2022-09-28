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
const int K = 1e6;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int P[K+1];
map<int, int> mk;

void solve(){
  int n; scanf("%d", &n);
  vector<int> a(n);
  mk.clear();
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    vector<int> b;
    while(a[i] > 1){
      b.push_back(P[a[i]]);
      a[i] /= P[a[i]];
    }
    int cnt = 1;
    b.push_back(1);
    for(int j=1; j<sz(b); j++){
      if(b[j] != b[j-1]){
        if(cnt % 2 == 1)
          a[i] *= b[j-1];
        cnt = 1;
      }
      else cnt++;
    }
    mk[a[i]]++;
  }
  int zer = 0, one = 0;
  for(auto i : mk){
    if(i.ff == 1 || i.ss % 2 == 0)
      one += i.ss;
    zer = max(zer, i.ss);
  }
  int q; scanf("%d", &q);
  while(q--){
    int w; scanf("%d", &w);
    if(w == 0) printf("%d\n", zer);
    else printf("%d\n", max(zer, one));
  }
}

int main(){
  for(int i=2; i<=K; i++){
    if(P[i] > 0) continue;
    for(int j=i; j<=K; j+=i)
      P[j] = i;
  }
  
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
