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

const int N = 1e6+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

char s[N];


bool check(vector<int> &L, vector<int> &R){
  int diff = 0;
  for(int i=0; i<26; i++){
    if(L[i] != R[i]){
      diff++;
    }
  }
  return diff == 1;
}

void solve(){
  scanf("%s", s);
  int n = strlen(s);
  vector<vector<int>> a(26, vector<int>(n+1, 0));
  for(int i=0; i<n; i++){
    a[s[i]-'a'][i]++;
    for(int j=0; j<26; ++j){
      if(i > 0)
        a[j][i] += a[j][i-1];
    }
  }
  int q; scanf("%d", &q);
  int ans = 0;
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    --l, --r;
    if((r-l+1) % 2 == 0) continue;
    vector<int> L(26, 0), R(26, 0);
    int midd = mid(l, r);
    for(int i=0; i<26; i++){
      L[i] = a[i][midd] - (l > 0 ? a[i][l-1] : 0);
      R[i] = a[i][r] - a[i][midd];
    }
    if(check(L, R)){
      ans++;f
      continue;
    }
    L[s[midd]-'a']--;
    R[s[midd]-'a']++;
    if(check(L, R)){
      ans++;
      continue;
    }
    //~ printf("---> %d, %d, %d\n", l, r, midd);
  }
  printf("%d\n", ans);
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
