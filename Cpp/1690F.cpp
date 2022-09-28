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

char s[201];

void solve(){
  int n;
  scanf("%d%s", &n, s);
  vector<int> a(n), vis(n);
  vector<vector<int>> cycles;
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    a[i]--;
  }
  for(int i=0; i<n; i++){
    if(vis[i] == 0){
      vector<int> v;
      int cur = i;
      while(vis[cur] == 0){
        vis[cur] = 1;
        v.push_back(cur);
        cur = a[cur];
      }
      cycles.push_back(v);
    }
  }
  int m = cycles.size();
  vector<int> periods(m);
  for(int i=0; i<m; i++){
    int cyclesize = cycles[i].size();
    for(int j=1; j<=cyclesize; j++){
      if(cyclesize % j == 0){
        bool fine = true;
        for(int k=j; k<cyclesize; k++){
          if(s[cycles[i][k]] != s[cycles[i][k-j]]){
            fine = false;
            break;
          }
        }
        if(fine){
          periods[i] = j;
          break;
        }
      }
    }
  }
  assert(sz(periods) > 0);
  long long curLcm = periods[0];
  for(int i=1; i<m; i++){
    long long gicidi = __gcd(curLcm, (long long)periods[i]);
    curLcm = (curLcm * periods[i]) / gicidi;
  }
  printf("%lld\n", curLcm);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
