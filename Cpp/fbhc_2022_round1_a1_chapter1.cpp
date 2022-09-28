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

int n, k;
vector<int> A, B;
map<int, int> cnt;

bool check(int x, int y){
  for(int i=0; i<n; i++){
    if(A[x] != B[y]){
      return false;
    }
    x = (x+1) % n;
    y = (y+1) % n;
  }
  return true;
}

void solve(){
  scanf("%d%d", &n, &k);
  A.resize(n), B.resize(n); cnt.clear();
  for(int i=0; i<n; i++){
    scanf("%d", &A[i]);
  }
  for(int i=0; i<n; i++){
    scanf("%d", &B[i]);
    cnt[B[i]]++;
  }
  int mini = n+1, thenum = -1;
  for(auto i : cnt){
    if(i.ss < mini){
      mini = i.ss;
      thenum = i.ff;
    }
  }
  int theidx = -1;
  for(int i=0; i<n; i++){
    if(thenum == B[i]){
      theidx = i;
      break;
    }
  }
  //~ printf("mini->%d, thenum->%d, theidx->%d\n", mini, thenum, theidx);
  for(int i=0; i<n; i++){
    if(A[i] == thenum){
      if(!check(i, theidx)){
        continue;
      }
      if(i == theidx){
        if(k % 2 == 0 || (k > 1 && n > 2)){
          puts("YES");
          return;
        }
      } else {
        if((k-1) % 2 == 0 || (k > 1 && n > 2)){
          puts("YES");
          return;
        }
      }
    }
  }
  puts("NO");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  for(int i=1; i<=testcase; i++){
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
