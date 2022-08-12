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
  while(true){
    int n; scanf("%d", &n);
    if(n == 0) break;
    while(true){
      bool breakit = false;
      vector<int> a(n+1);
      for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        if(a[i] == 0){
          breakit = true;
          break;
        }
      }
      if(breakit) break;
      
      int p = 1;
      stack<int> st;
      for(int i=1; i<=n; i++){
        st.push(i);
        while(!st.empty() && p <= n && st.top() == a[p]){
          p++;
          st.pop();
        }
      }
      if(p == n+1)  puts("Yes");
      else puts("No");
    }
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
