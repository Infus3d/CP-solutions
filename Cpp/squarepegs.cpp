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
  int n,m,k;
  scanf("%d %d %d", &n, &m, &k);
  
  vector<int> plots;
  vector<double> houses;
  for(int i=0; i < n; i++){
      int inp;
      scanf("%d" , &inp);
      plots.push_back(inp);
      
  }
  for(int i = 0; i < m; i++){
      int inp;
      scanf("%d" , &inp);
      double x = inp*1.0;
      houses.push_back(x);
  }
  
  for(int i = 0; i < k; i++){
      int inp;
      scanf("%d" , &inp);
      
      double x = (inp/2.0)*sqrt(2);
      houses.push_back(x);
  }
  
  sort(plots.begin(), plots.end());
  sort(houses.begin(), houses.end());
  
  int ans = 0;
  int pidx = 0;
  int hidx = 0;
  
  while(pidx< (int)plots.size() && hidx < (int)houses.size()){
      if(houses[hidx] < plots[pidx]){
          ans++;
          hidx++;
          pidx++;
      } else {
          pidx++;
      }
      
      
  }
  
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  //scanf("%d  ", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
