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

int d[N];
ll sums[7][N];
multiset<ll> setik;

void solve(){
  int n, q;
  scanf("%d%d", &n, &q);
  for(int i=0; i<n; i++){
    scanf("%d", &d[i]);
  }
  int m = n, div = 2;
  vector<int> fac;
  while(m > 1){
    if(m % div == 0){
      m /= div;
      if(fac.empty() || fac.back() != div)
        fac.push_back(div);
    }
    else div++;
  }
  m = sz(fac);
  setik.clear();
  long long ans = 0;
  for(int i=0; i<m; i++){
    int jump = n / fac[i];
    fill(sums[i], sums[i]+jump, 0);
    for(int j=0; j<n; j++){
      sums[i][j%jump] += d[j];
    }
    for(int j=0; j<jump; j++){
      setik.insert(sums[i][j] * jump);
    }
    ans = max(ans, *setik.rbegin());
  }
  printf("%lld\n", ans);
  while(q--){
    int p, x;
    scanf("%d%d", &p, &x);
    p--, ans = 0;
    for(int i=0; i<m; i++){
      int jump = n / fac[i], j = p % jump;
      setik.erase(setik.find(sums[i][j] * jump));
      sums[i][j] += (-d[p] + x);
      setik.insert(sums[i][j] * jump);
    }
    d[p] = x;
    printf("%lld\n", *setik.rbegin());
  } 
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
