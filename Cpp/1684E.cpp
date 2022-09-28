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
  map<int, int> cnt;
  for(int i=0; i<n; i++){
    int a; scanf("%d", &a);
    cnt[a]++;
  }
  int maxi = n, zero = 0;
  for(int i=0; i<=n; i++){
    if(cnt[i] == 0) zero++;
    if(zero > k){
      maxi = i;
      break;
    }
  }
  multiset<int> setik;
  for(auto i : cnt){
    if(i.ff >= maxi && i.ss > 0)
      setik.insert(i.ss);
  }
  while(!setik.empty() && k >= *setik.begin()){
    int tr = *setik.begin();
    if(k >= tr){
      k -= tr;
      setik.erase(setik.begin());
    }
  }
  printf("%d\n", maxi+sz(setik) - maxi);
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
