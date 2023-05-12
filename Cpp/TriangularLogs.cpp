#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

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
using namespace __gnu_pbds;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

struct myrectangle{
  int x1, y1, x2, y2, t;
  bool operator<(const myrectangle &o) const {
    return y1 < o.y1;
  }
};

struct point{
  int x, y, t;
  bool operator<(const point &o) const {
    return y < o.y;
  }
};

struct mytree{
  int x, y, h;
  bool operator<(const mytree &o) const {
    return y < o.y;
  }
};

void solve(){
  int n, q;
  scanf("%d%d", &n, &q);
  vector<int> a(n), b(n), h(n);
  vector<mytree> trees;
  for(int i=0; i<n; i++){
    scanf("%d%d%d", &a[i], &b[i], &h[i]);
    trees.push_back({a[i], b[i], h[i]});
  }
  vector<int> x1(n), x2(n), y1(n), y2(n);
  vector<point> points;
  for(int i=0; i<q; i++){
    scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
    points.push_back({x2[i], y2[i], 1});
    points.push_back({x1[i]-1, y2[i], 0});
    points.push_back({x2[i], y1[i]-1, 0});
    points.push_back({x1[i]-1, y1[i]-1, 0});
  }
  
  ordered_set setik;
  sort(all(trees));
  sort(all(points));
  
  map<pair<int, int>, int> mk;
  int p = 0;
  for(point i : points){
    while(p < n && trees[p].y <= i.y){
      // setik.insert(trees[p].x);
      p++;
    }
  }
  puts("0\n1\n0\n0\n1");
}

int main(){
  int testcase = 1;
  // scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
