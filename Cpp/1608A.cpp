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

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

int n, a, b, d[N];

void solve(){
  scanf("%d%d%d", &n, &a, &b);
  if(abs(a-b) > 1 || (a+b) > n-2) { puts("-1"); return; }
  if(min(a, b) >= n/2) { puts("-1"); return; }
  if(a > b){
    int p = n-1;
    int i = 1;
    for(; i<=n && a > 0; i+=2, a--){
      d[i] = p, d[i+1] = p+1;
      p -= 2;
    }
    p++;
    for(; i<=n; i++, p--)
      d[i] = p;
  }
  else if(a == 0 && b == 0){
    for(int i=1; i<=n; i++)
      d[i] = i;
  }
  else if(b > a){
    int p = 2;
    int i = 1;
    for(; i<=n && b > 0; i+=2, b--){
      d[i] = p, d[i+1] = p-1;
      p += 2;
    }
    p--;
    for(; i<=n; i++, p++)
      d[i] = p;
  }
  else{
    int p = 2;
    int i = 1;
    for(; i<=n && b > 0; i+=2, b--){
      d[i] = p, d[i+1] = p-1;
      p += 2;
    }
    p = n;
    for(; i<=n; i++, p--)
      d[i] = p;
  }
  for(int i=1; i<=n; i++)
    printf("%d ", d[i]);
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
