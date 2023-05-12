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

#define rep(i, a, b) for(int i=a; i<(b); i++)

using namespace std;

typedef vector<int> vi;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

array<vi, 2> manacher(const vector<int> &s){
  int n = sz(s);
  array<vi, 2> p = {vi(n+1), vi(n)};
  rep(z, 0, 2) for(int i=0,l=0,r=0; i<n; i++){
    int t = r-i+!z;
    if(i<r) p[z][i] = min(t, p[z][l+t]);
    int L = i-p[z][i], R = i+p[z][i]-!z;
    while(L >= 1 && R+1 < n && s[L-1] == s[R+1])
      p[z][i]++, L--, R++;
    if(R > r) l = L, r = R;
  }
  return p;
}

void solve(){
  int n; scanf("%d", &n);
  vector<int> a(n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  
  array<vi, 2> ret = manacher(a);
  vector<int> left(n), right(n);
  
  left[0] = 1;
  for(int i=1; i<n; i++){
    if(a[i] > a[i-1]) left[i] = left[i-1] + 1;
    else left[i] = 1;
  }
  
  right[n-1] = 1;
  for(int i=n-2; i>=0; i--){
    if(a[i] > a[i+1]) right[i] = right[i+1] + 1;
    else right[i] = 1;
  }
  
  int ans = 0;
  for(int i=0; i<n; i++){
    // printf("dumping i->%d\n", i);
    // printf("ret[1][i] -> %d, right[i] -> %d, left[i] -> %d\n", ret[1][i], right[i], left[i]);
    int cur = min(ret[1][i], min(right[i]-1, left[i]-1));
    ans = max(ans, cur);
  }
  ans = ans*2+1;
  // printf("preliminary ans: %d\n", ans);
  if(ans < 3) ans = -1;
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
/*
7
3 4 5 4 3 2 1  
*/
