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

int n, d[N], cnt[N];
vector<int> E[N];

void solve(){
  set<int> setik;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &d[i]), E[d[i]].clear();
  for(int i=1; i<=n; i++){
    E[d[i]].push_back(i);
    setik.insert(d[i]);
  }
  while(!setik.empty()){
    int cur = *setik.begin();
    int curInd = E[cur].back();
    E[cur].pop_back(); 
    if(sz(E[cur]) == 0) setik.erase(cur);
    //~ printf("%d %d\n", cur, curInd);
    
    vector<int> v;
    for(auto i=setik.begin(); i!=setik.end(); i++){
      if(*i == cur) continue;
      int temp = *i;
      int tempInd = E[temp].back();
      E[temp].pop_back();
      v.push_back(temp);
      
      swap(d[curInd], d[tempInd]);
      curInd = tempInd;
      cur = temp;
    }
    for(int i : v)
      if(sz(E[i]) == 0)
        setik.erase(i);
  }
  
  for(int i=1; i<=n; i++) printf("%d ", d[i]);
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
