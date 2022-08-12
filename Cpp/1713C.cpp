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
  vector<int> x{0}, y{0};
  for(int i=0; i<n; i++){
    int a, b; scanf("%d%d", &a, &b);
    if(a == 0) x.push_back(b);
    if(b == 0) y.push_back(a);
  }
  sort(all(x));
  sort(all(y));
  int a = sz(x), b = sz(y);
  printf("%d\n", 2*((x[a-1]-x[0])+(y[b-1]-y[0])));
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
