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
const int MOD = 1e9+7;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

int add(int x, int y){
  return ((x + y) % MOD + MOD) % MOD;
}

int mul(int x, int y){
  return ((1LL * x * y) % MOD + MOD) % MOD;
}

int calc(vector<int> &a, vector<int> &b){
  int n = sz(a), m = sz(b);
  int baseSquareSum = 0, baseSum = 0;
  assert(n > 0);
  for(int i : b){
    int dist = i - a[0];
    baseSum = add(baseSum, dist);
    baseSquareSum = add(baseSquareSum, mul(dist, dist));
  }
  int ret = baseSquareSum;
  for(int i=1; i<n; i++){
    int k = a[0] - a[i];
    int newSquareSum = add(baseSquareSum, mul(mul(k, k), m));
    newSquareSum = add(newSquareSum, mul(baseSum, mul(k, 2)));
    ret = add(ret, newSquareSum);
  }
  return ret;
}

void solve(){
  int n; scanf("%d", &n);
  vector<int> treex, treey;
  for(int i=0; i<n; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    treex.push_back(a);
    treey.push_back(b);
  }
  int m; scanf("%d", &m);
  vector<int> wellx, welly;
  for(int i=0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    wellx.push_back(a);
    welly.push_back(b);
  }
  sort(all(treex)); reverse(all(treex));
  sort(all(treey)); reverse(all(treey));
  int ans = (calc(treex, wellx) + calc(treey, welly)) % MOD;
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
