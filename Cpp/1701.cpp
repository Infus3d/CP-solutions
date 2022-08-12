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

const int N = 5e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, a[N], b[N], l[N], r[N];
vector<int> E[N];

void solve(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    E[i].clear();
  for(int i=1; i<=n; i++){
    scanf("%d", &b[i]);
    r[i] = (!b[i] ? n : i/b[i]);
    l[i] = (i / (b[i]+1))+1;
    E[l[i]].push_back(i);
  }
  
  set<pii> setik;
  for(int i=1; i<=n; i++){
    for(int j : E[i])
      setik.insert({r[j], j});
    
    assert(setik.size() > 0);
    
    pii cur = *setik.begin();
    setik.erase(setik.begin());
    
    a[cur.ss] = i;
  }
  
  for(int i=1; i<=n; i++)
    printf("%d ", a[i]);
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
