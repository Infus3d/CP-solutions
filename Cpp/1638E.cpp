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

struct inval{
  int l, r, c;
  inval() : l(), r(), c() {};
  inval(int _l, int _r, int _c) : l(_l), r(_r), c(_c) {}
  void scant(){
    scanf("%d%d%d", &l, &r, &c);
  }
  bool operator< (const inval &o) const {
    if(this->l == o.l) return this->r < o.r;
    else return this->l < o.l;
  }
};
set<inval> setik;

int n, q;
ll T[N<<2], col[N];
char t[10];

void upd(int x, int y, ll val, int l, int r, int v){
  if(r < x || y < l) return;
  if(x <= l && r <= y){
    T[v] += val;
    return;
  }
  upd(x, y, val, l, mid(l, r), v<<1);
  upd(x, y, val, mid(l, r)+1, r, v<<1|1);
}

ll getInd(int x, int l, int r, int v){
  if(l == r) return T[v];
  if(x <= mid(l, r)) return T[v] + getInd(x, l, mid(l, r), v<<1);
  return T[v] + getInd(x, mid(l, r)+1, r, v<<1|1);
}

void solve(){
  scanf("%d%d", &n, &q);
  setik.insert(inval(1, n, 1));
  while(q--){
    scanf("%s", t);
    if(t[0] == 'C'){
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      auto lef = setik.lower_bound(inval(a+1, 0, 0));
      if(lef != setik.begin()) lef--;
      if(((*lef).r > a) || ((*lef).r == a && (*lef).l < a)){
        auto lefVal = *lef;
        setik.erase(lefVal);
        if(lefVal.l <= a-1)
          setik.insert(inval(lefVal.l, a-1, lefVal.c));
        setik.insert(inval(a, lefVal.r, lefVal.c));
        lef = --setik.lower_bound(inval(a+1, 0, 0));
      }
      
      auto rig = setik.lower_bound(inval(b+1, 0, 0));
      if(rig != setik.begin()) rig--;
      if((*rig).r > b){
        auto rigVal = *rig;
        setik.insert(inval(rigVal.l, b, rigVal.c));
        setik.insert(inval(b+1, rigVal.r, rigVal.c));
        //~ printf("what happens: rigval.l:%d, b:%d, rigVal.c:%d\n", rigVal.l, b, rigVal.c);
        //~ printf("what happens: b+1:%d, rigVal.r:%d, rigVal.c:%d\n", b+1, rigVal.r, rigVal.c);
        setik.erase(rigVal);
        rig = --setik.lower_bound(inval(b+1, 0, 0));
      }
      rig++;
      
      //~ printf("lef -> l:%d, r:%d, c:%d\n", lef->l, lef->r, lef->c);
      //~ printf("rig -> l:%d, r:%d, c:%d\n", rig->l, rig->r, rig->c);
      
      auto it = setik.lower_bound(inval(a, 0, 0));
      while(it != setik.end() && it->l <= b){
        //~ printf("it -> l:%d, r:%d, c:%d\n", it->l, it->r, it->c);
        upd(it->l, it->r, col[it->c], 1, n, 1);
        setik.erase(*it);
        it = setik.lower_bound(inval(a, 0, 0));
      }
      
      upd(a, b, -col[c], 1, n, 1);
      setik.insert(inval(a, b, c));
    }
    else if(t[0] == 'A'){
      int a, b; scanf("%d%d", &a, &b);
      col[a] += b;
    }
    else if(t[0] == 'Q'){
      int a; scanf("%d", &a);
      auto interval = --setik.lower_bound(inval(a, n+2, 0));
      assert(interval != setik.end());
      printf("%lld\n", col[interval->c] + getInd(a, 1, n, 1));
    }
  }
}

/*

[1 5] [6 10]
 [4 7]

*/

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
