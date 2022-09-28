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

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, -1, 0, +1};

void solve(){
  int n; scanf("%d", &n);
  set<pair<int, int>> setik;
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++){
    scanf("%d%d", &a[i], &b[i]);
    setik.insert({a[i], b[i]});
  }
  queue<pair<int, int>> Q;
  map<pair<int, int>, pair<int, int>> mk;
  for(int i=0; i<n; i++){
    for(int j=0; j<4; j++){
      int newx = a[i] + dx[j];
      int newy = b[i] + dy[j];
      if(setik.find({newx, newy}) == setik.end()){
        mk[{a[i], b[i]}] = {newx, newy};
        Q.push({a[i], b[i]});
        break;
      }
    }
  }
  while(!Q.empty()){
    auto [x, y] = Q.front();
    Q.pop();
    for(int i=0; i<4; i++){
      int newx = x + dx[i];
      int newy = y + dy[i];
      if(setik.find({newx, newy}) != setik.end() && !mk.count({newx, newy})){
        mk[{newx, newy}] = mk[{x, y}];
        Q.push({newx, newy});
      }
    }
  }
  for(int i=0; i<n; i++){
    printf("%d %d\n", mk[{a[i], b[i]}].ff, mk[{a[i], b[i]}].ss);
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
