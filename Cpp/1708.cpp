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

const int N = 5e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, q;
vector<int> a;

bool fine(int x){
  int cur = q;
  for(int i=x; i<=n; i++){
    if(a[i] > cur)
      cur--;
  }
  return (cur >= 0);
}

void solve(){
  scanf("%d%d", &n, &q);
  a.resize(n+1);
  for(int i=1; i<=n; i++)
    scanf("%d", &a[i]);
  
  int l = 0, r = n;
  while(l+1 < r){
    if(fine(mid(l, r)))
      r = mid(l, r);
    else
      l = mid(l, r);
  }
  
  for(int i=1; i<=n; i++){
    if(i < r && a[i] <= q)
      printf("1");
    else if(i >= r)
      printf("1");
    else
      printf("0");
  }
  puts("");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
