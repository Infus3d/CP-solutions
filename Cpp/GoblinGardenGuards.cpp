#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define sqr(x) ((x) * (x))
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)	x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2e4+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int n, m;
vector<pii> goblin, sprink;
multiset<int> setik[N];

bool fine(int curx, int cury, int x, int y, int r){
  return (sqr(abs(curx - x)) + sqr(abs(cury - y)) <= r * r);
}

void solve(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    int a, b; scanf("%d%d", &a, &b);
    setik[a].insert(b);
  }
  scanf("%d", &m);
  for(int i=1; i<=m; i++){
    int a, b, c; 
    scanf("%d%d%d", &a, &b, &c);
    
    int limit = 0;
    for(int j=max(0, a-c); j<=min((int)1e4, a+c); j++){
      while(fine(j, b+limit+1, a, b, c)) limit++;
      while(!fine(j, b+limit, a, b, c)) limit--;
      
      auto it = setik[j].lower_bound(b - limit);
      vector<int> toDelete;
      while(it != setik[j].end()){
        if(!fine(j, *it, a, b, c)) break;
        toDelete.push_back(*it);
        it++;
      }
      
      for(int k : toDelete){
        assert(setik[j].find(k) != setik[j].end());
        setik[j].erase(setik[j].find(k));
      }
    }
  }
  
  int ans = 0;
  for(int i=0; i<=(int)1e4; i++)
    ans += sz(setik[i]);
  printf("%d\n", ans);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
