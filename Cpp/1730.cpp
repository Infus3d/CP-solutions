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
  scanf("%s", s);
  int n = strlen(s);
  assert(n < N);
  set<pair<int, int>> setik;
  multiset<int> a;
  for(int i=0; i<n; i++){
    setik.insert({s[i]-'0', i});
  }
  int cur = -1;
  while(cur < n && !setik.empty()){
    auto tr = *setik.begin();
    while(!a.empty() && *a.begin() <= tr.ff){
      printf("%d", *a.begin());
      a.erase(a.begin());
    }
    printf("%d", tr.ff);
    for(int i=cur+1; i<tr.ss; i++){
      setik.erase({s[i]-'0', i});
      a.insert(min(s[i]-'0'+1, 9));
    }
    setik.erase(tr);
    cur = tr.ss;
  }
  while(!a.empty()){
    printf("%d", *a.begin());
    a.erase(a.begin());
  }
  puts("");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
