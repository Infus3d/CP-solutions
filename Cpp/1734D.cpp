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

void solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a(n);
  vector<pair<long long, long long>> L, R;
  long long score = 0;
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
    if(i == k-1)
      score = a[i];
  }
  long long cursum = 0, curmin = (long long)1e18;
  for(int i=k-2; i>=0; i--){
    cursum += a[i];
    curmin = min(curmin, cursum);
    if(cursum >= 0 || i == 0){
      L.push_back({cursum, -curmin});
      cursum = 0;
      curmin = (long long)1e18;
    }
  }
  cursum = 0, curmin = (long long)1e18;
  for(int i=k; i<n; i++){
    cursum += a[i];
    curmin = min(curmin, cursum);
    if(cursum >= 0 || i == n-1){
      R.push_back({cursum, -curmin});
      cursum = 0;
      curmin = (long long)1e18;
    }
  }
  //~ printf("L\n");
  //~ for(pii i : L) printf("%d %d\n", i.ff, i.ss);
  //~ printf("R\n");
  //~ for(pii i : R) printf("%d %d\n", i.ff, i.ss);
  if(k == 1 || k == n){
    puts("YES");
    return;
  }
  int l = 0, r = 0;
  while(l < sz(L) || r < sz(R)){
    if(l == sz(L)-1 && score >= L[l].ss){
      puts("YES");
      return;
    }
    if(r == sz(R)-1 && score >= R[r].ss){
      puts("YES");
      return;
    }
    if(L[l].ff >= 0 && L[l].ss <= score){
      score += L[l].ff;
      l++;
    }
    else if(R[r].ff >= 0 && R[r].ss <= score){
      score += R[r].ff;
      r++;
    }
    else{
      puts("NO");
      break;
    }
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
