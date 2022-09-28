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
  int n;
  scanf("%d%s", &n, s);
  int odd = 0, idx = -1;
  for(int i=0; i<n; i++){
    if(s[i] == '1'){
      odd++;
      idx = i;
    }
  }
  if(idx == -1 || odd % 2 == 1){
    puts("NO");
    return;
  }
  puts("YES");
  vector<int> v;
  int las = -1;
  idx = (idx+1)%n;
  for(int rep=0; rep<n; rep++){
    if(s[idx] == '0'){
      if(las == -1){
        v.push_back(idx);
        las = idx;
      }
      else{
        printf("%d %d\n", (idx-1+n)%n+1, idx+1);
      }
    }
    else{
      if(las == -1){
        v.push_back(idx);
      }
      else{
        printf("%d %d\n", (idx-1+n)%n+1, idx+1);
        las = -1;
      }
    }
    idx = (idx+1)%n;
  }
  assert(sz(v) % 2 == 0);
  for(int i=1; i<sz(v); i++){
    printf("%d %d\n", v[0]+1, v[i]+1);
  }
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
