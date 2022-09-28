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

char s[N];

void solve(){
  int n; scanf("%d", &n); n *= 2;
  scanf("%s", s+1);
  stack<int> st;
  vector<int> vis(n+1);
  st.push(0);
  for(int i=1; i<=n; i++){
    if(s[i] == '('){
      st.push(i);
    } else {
      st.pop();
      vis[st.top()] = 1;
    }
  }
  printf("%d\n", accumulate(all(vis), 0));
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
