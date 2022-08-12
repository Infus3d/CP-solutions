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
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for(int i=0; i<n; i++)
    scanf("%d", &a[i]);
  
  stack <int> mini, maxi;
  vector<int> nextmin(n), nextmax(n);
  for(int i=n-1; i>=0; i--){
    while(!mini.empty() && a[mini.top()] > a[i]) mini.pop();
    while(!maxi.empty() && a[maxi.top()] < a[i]) maxi.pop();
    
    nextmin[i] = (mini.empty() ? n : mini.top());
    nextmax[i] = (maxi.empty() ? n : maxi.top());
    mini.push(i);
    maxi.push(i);
  }
  
  int cur = 0, ans = 0;
  while(cur < n-1){
    if(a[cur] < a[cur+1]){
      int lim = nextmin[cur];
      while(nextmax[cur] < lim)
        cur = nextmax[cur];
    } else {
      int lim = nextmax[cur];
      while(nextmin[cur] < lim)
        cur = nextmin[cur];
    }
    ans++;
  }
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
