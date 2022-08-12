#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define db puts("*****")
#define mid(x , y) ((x+y)>>1)
#define ff first
#define ss second
#define all(x)	x.begin(),x.end()
#define ll long long
#define sqr(x)	((x)*(x))
#define pii pair <int , int>
#define pll pair <ll, ll>
#define sz(x) int(x.size())
#define tr(it , c) for(__typeof(c.begin()) it = (c.begin()); it != (c.end()); it++)
#define y1 your_name_engraved_herein
#define ook order_of_key

using namespace std;
using namespace __gnu_pbds;

const int N = 1e5+2;
const int M = 600;
const int MOD = 1e9+7;
const int K = 1e3+2;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0;}
template<class T> bool umod(T& a) { while(a < 0) a += MOD; a %= MOD; return 1;}
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

//	freopen("file.in" , "r" , stdin);
//	freopen("file.out" , "w" , stdout);

int n, k;
int a[N], location[N], sora[N], cnt[N];

int T[N<<2], lz[N<<2];
map<int, int> mk, lp;

void proc(int v, int val){
  T[v] += val;
  lz[v] += val;
}

void push(int l, int r, int v){
  if(!lz[v]) return;
  proc(v<<1, lz[v]);
  proc(v<<1|1, lz[v]);
  lz[v] = 0;
}

void upd(int x, int y, int val, int l=0, int r=n-1, int v=1){
  if(r < x || y < l) return;
  if(x <= l && r <= y){
    proc(v, val);
    return;
  }
  push(l, r, v);
  upd(x, y, val, l, mid(l, r), v<<1);
  upd(x, y, val, mid(l, r)+1, r, v<<1|1);
  T[v] = min(T[v<<1], T[v<<1|1]);
}

int get(int x, int y, int l=0, int r=n-1, int v=1){
  if(l == r) return T[v];
  push(l, r, v);
  if(x <= mid(l, r))  return get(x, y, l, mid(l, r), v<<1);
  else return get(x, y, mid(l, r)+1, r, v<<1|1);
}

int walk(int l=0, int r=n-1, int v=1){
  //~ printf("l:%d, r:%d, v:%d, T[v]:%d\n", l, r, v, T[v]);
  if(l == r) return l;
  push(l, r, v);
  if(T[v<<1] == 0)  return walk(l, mid(l, r), v<<1);
  else return walk(mid(l, r)+1, r, v<<1|1);
}

void setit(int x, int val, int l=0, int r=n-1, int v=1){
  if(l == r){
    T[v] = val;
    lz[v] = 0;
    return;
  }
  push(l, r, v);
  if(x <= mid(l ,r))
    setit(x, val, l, mid(l, r), v<<1);
  else
    setit(x, val, mid(l, r)+1, r, v<<1|1);
  T[v] = min(T[v<<1], T[v<<1|1]);
}

template<class T, class U> T fstTrue(T lo, T hi, U f) {
  --lo; assert(lo <= hi); // assuming f is increasing
  if(!f(hi)) return -1;
	while (lo + 1 < hi) { // find first index such that f is true 
		T mid = (lo+hi)/2;
		f(mid) ? hi = mid : lo = mid; 
	}
	return hi;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
	++hi; assert(lo <= hi); // assuming f is decreasing
  if(!f(lo)) return -1;
	while (lo + 1 < hi) { // find last index such that f is true 
		T mid = (lo+hi)/2;
		f(mid) ? lo = mid : hi = mid;
	} 
	return lo;
}

int main(){
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; i++) scanf("%d", &a[i]);
  for(int i=0; i<n; i++) sora[i] = i;
  sort(sora, sora+n, [&](int x, int y){
    return a[x] < a[y];
  });
  for(int i=0; i<n; i++) location[sora[i]] = i;
  //~ for(int i=0; i<n; i++) mk[a[sora[i]]] = i;
  //~ for(int i=n-1; i>=0; i--) lp[a[sora[i]]] = i;
  
  ordered_set setik;
  for(int i=0; i<n; i++){
    setik.insert({a[i], i});
    int numBefore = setik.ook({a[i]-k, -1});
    numBefore += setik.size() - setik.ook({a[i]+k+1, -1});
    upd(location[i], location[i], numBefore);
  }
  
  vector<int> ans;
  for(int i=0; i<n; i++){
    //~ printf("Iteration:%d\n", i);
    int idx = walk(0, n-1, 1);
    printf("%d\n", a[sora[idx]]);
    setit(idx, MOD*2, 0, n-1, 1);
    
    int left_bound = lstTrue(0, n-1, [&](int p){
      return a[sora[p]] < a[sora[idx]]-k;
    });
    
    int right_bound = fstTrue(0, n-1, [&](int p){
      return a[sora[p]] > a[sora[idx]]+k;
    });
    
    if(~left_bound) upd(0, left_bound, -1);
    if(~right_bound) upd(right_bound, n-1, -1);
    
    //~ int left_bound = setik.ook({a[sora[idx]]-k, -1})-1;
    //~ int right_bound = setik.ook({a[sora[idx]]+k+1, -1});
    //~ if(left_bound >= 0){
      //~ left_bound = setik.find_by_order(left_bound)->first;
      //~ upd(0, mk[left_bound], -1);
    //~ }
    //~ if(right_bound < n){
      //~ right_bound = setik.find_by_order(right_bound)->first;
      //~ upd(lp[right_bound], n-1, -1);
    //~ }
  }
  
  return 0;
}
