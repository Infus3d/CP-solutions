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

int n, d[N], cn[N];
ll ans[N];
set<int> setik;

void solve(){
  setik.clear();
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &d[i]);
    cn[d[i]]++;
    ans[i] = ans[i+1] = -1LL;
  }
  
  ll sofar = 0LL;
  for(int i=0; i<=n; i++){
    ans[i] = sofar + cn[i];
    if(cn[i] == 0){
      bool found = false;
      while(!setik.empty()){
        ll top = *(--setik.end());
        if(cn[top] < 2)
          setik.erase(top);
        else{
          found = true;
          cn[top]--;
          sofar += i-top;
          break;
        }
      }
      
      if(!found) break;
    }
    if(cn[i] > 1) 
      setik.insert(i);
  }
  
  for(int i=0; i<=n; i++){
    printf("%lld ", ans[i]);
    cn[i] = 0;
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
