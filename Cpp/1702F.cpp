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
  int n; scanf("%d", &n);
  vector<int> a(n), b(n);
  map<int, int> mk;
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    while(a[i] % 2 == 0)
      a[i] /= 2;
    mk[a[i]]++;
  }
  int cnt = 0;
  for(int i=0; i<n; i++){
    scanf("%d", &b[i]);
    while(b[i] > 0){
      if(mk[b[i]] > 0){
        mk[b[i]]--;
        cnt++;
        break;
      }
      b[i] /= 2;
    }
  }
  
  printf("%s\n", (cnt == n ? "YES" : "NO"));
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
