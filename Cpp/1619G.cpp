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

struct mine{
  int x, y, t;
};

void solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  map<int, set<pair<int, int>>> coorsx, coorsy;
  vector<int> par(n, 0), sorted;
  vector<mine> mines;
  for(int i=0; i<n; i++){
    int x, y, t;
    scanf("%d%d%d", &x, &y, &t);
    mines.push_back((mine){x, y, t});
    coorsx[x].insert({y, i});
    coorsy[y].insert({x, i});
    sorted.push_back(i);
  }
  int cnt = 0;
  queue<int> Q;
  for(int i=0; i<n; i++){
    if(par[i]) continue;
    assert(Q.empty());
    Q.push(i);
    par[i] = ++cnt;
    while(!Q.empty()){
      int cur = Q.front(); Q.pop();
      auto it = coorsx[mines[cur].x].lower_bound({mines[cur].y-k, -1});
      while(it != coorsx[mines[cur].x].end() && it->first <= (mines[cur].y+k)){
        if(par[it->second] == 0){
          Q.push(it->second);
          par[it->second] = cnt;
        }
        pii temp = *it;
        it++;
        coorsx[mines[cur].x].erase(temp);
        if(coorsx[mines[temp.ss].y].find({mines[temp.ss].x, temp.ss}) != coorsx[mines[temp.ss].y].end())
          coorsx[mines[temp.ss].y].erase({mines[temp.ss].x, temp.ss});
      }
      it = coorsy[mines[cur].y].lower_bound({mines[cur].x-k, -1});
      while(it != coorsy[mines[cur].y].end() && it->first <= (mines[cur].x+k)){
        if(par[it->second] == 0){
          Q.push(it->second);
          par[it->second] = cnt;
        }
        pii temp = *it;
        it++;
        coorsy[mines[cur].y].erase(temp);
        if(coorsy[mines[temp.ss].x].find({mines[temp.ss].y, temp.ss}) != coorsy[mines[temp.ss].y].end())
          coorsy[mines[temp.ss].x].erase({mines[temp.ss].y, temp.ss});
      }
    }
  }
  sort(all(sorted), [&](int x, int y){
    return mines[x].t < mines[y].t;
  });
  //~ printf("cnt -> %d\n", cnt);
  vector<int> vis(n+1, 0);
  int p = 0;
  for(int i=0; i<=n; i++){
    while(p < n && mines[sorted[p]].t <= i){
      if(!vis[par[sorted[p]]]){
        cnt--;
        vis[par[sorted[p]]] = 1;
      }
      p++;
    }
    if(cnt <= i+1){
      printf("%d\n", i);
      return;
    }
  }
  assert(false);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
