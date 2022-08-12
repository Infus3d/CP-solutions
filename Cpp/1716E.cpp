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

const int N = 2e5+5;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

struct node{
  ll pref, suf, sum, maxi;
  node(){
    pref = suf = sum = maxi = 0;
  }
  node(ll val){
    pref = suf = sum = val;
    maxi = max(0LL, val);
  }
  node(node &lef, node &rig){
    sum = lef.sum + rig.sum;
    pref = max(lef.pref, lef.sum + rig.pref);
    suf = max(rig.suf, rig.sum + lef.suf);
    maxi = max(lef.suf + rig.pref, max(lef.maxi, rig.maxi));
  }
};

void solve(){
  int h; scanf("%d", &h);
  int n = (1<<h);
  vector<int> a(n);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  vector<vector<node>> T(n*2);
  for(int i=0; i<n; i++){
    T[i+n].push_back(node(a[i]));
  }
  
  for(int i=n-1; i>0; i--){
    vector<node> &vl = T[i*2], &vr = T[i*2+1];
    //~ printf("i --> %d, sz(vl)->%d, sz(vr)->%d\n", i, sz(vl), sz(vr));5
    assert(sz(vl) == sz(vr));
    for(int j=0; j<sz(vl); j++)
      T[i].push_back(node(vl[j], vr[j]));
    for(int j=0; j<sz(vr); j++)
      T[i].push_back(node(vr[j], vl[j]));
  }
  
  int cur = 0, q; scanf("%d", &q);
  while(q--){
    int k; scanf("%d", &k);
    cur ^= (1<<k);
    printf("%lld\n", max(0LL, T[1][cur].maxi));
  }
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
