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

int n, d[N], a[N], b[N], mxa, mxb, p1, p2;
pii aa[N], bb[N];

void rec(int turn){
  if(turn){
    int temp = mxa;
    while(p1 <= n && bb[p1].ff <= mxb){
      umax(mxa, a[bb[p1].ss]);
      p1++;
    }
    if(temp < mxa)
      rec(0);
  }
  else{
    int temp = mxb;
    while(p2 <= n && aa[p2].ff <= mxa){
      umax(mxb, b[aa[p2].ss]);
      p2++;
    }
    if(temp < mxb)
      rec(1);
  }
}

void solve(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d", &a[i]), aa[i] = {a[i], i};
  for(int i=1; i<=n; i++)
    scanf("%d", &b[i]), bb[i] = {b[i], i};
  
  sort(aa+1, aa+n+1);
  sort(bb+1, bb+n+1);
  
  mxa = 0, mxb = 0, p1 = 1, p2 = 1;
  for(int i=1; i<=n; i++){
    umax(mxa, aa[i].ff);
    umax(mxb, b[aa[i].ss]);
    rec(1);
    if(mxa == aa[n].ff || mxb == bb[n].ff)
      d[aa[i].ss] = 1;
    else
      d[aa[i].ss] = 0;
  }
  
  for(int i=1; i<=n; i++)
    printf("%d", d[i]);
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
