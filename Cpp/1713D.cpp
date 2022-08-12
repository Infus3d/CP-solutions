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
  int h; scanf("%d", &h);
  int n = (1<<h);
  vector<int> v(n);
  for(int i=0; i<n; i++)
    v[i] = i+1;
  while(n > 2){
    vector<int> curv;
    for(int i=0; i<n; i+=4){
      int a = v[i], b = v[i+1];
      int c = v[i+2], d = v[i+3];
      printf("? %d %d\n", a, c);
      int verdict; scanf("%d", &verdict);
      int e, f;
      if(verdict == 1) e = a, f = d;
      else if(verdict == 2) e = b, f = c;
      else e = b, f = d;
      printf("? %d %d\n", e, f);
      scanf("%d", &verdict);
      assert(verdict != 0);
      if(verdict == 1) curv.push_back(e);
      else curv.push_back(f);
    }
    v = curv;
    n /= 4;
  }
  if((int)v.size() == 2){
    printf("? %d %d\n", v[0], v[1]);
    int verdict; scanf("%d", &verdict);
    if(verdict == 2)
      swap(v[0], v[1]);
    v.pop_back();
  }
  printf("! %d\n", v[0]);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
