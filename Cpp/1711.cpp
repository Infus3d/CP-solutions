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

ll n, m, k, d[N], dd[N];

void solve(){
  scanf("%lld%lld%lld", &n, &m, &k);
  for(int i=1; i<=k; i++)
    scanf("%lld", &d[i]);
  sort(d+1, d+k+1);
  
  ll odd = 0, even = 0, sum = 0;
  for(int i=1; i<=k; i++){
    dd[i] = d[i] / n;
    if(dd[i] < 2) continue;
    if(dd[i] % 2)
      odd++;
    else if(dd[i] > 2)
      even++;
    sum += dd[i];
  }
  if(m % 2 == 0 || (odd > 0 || even > 0)){
    if(m % 2 == 1 && odd % 2 == 0) sum--;
    if(sum >= m){
      puts("Yes");
      return;
    }
  }
  
  odd = 0, even = 0, sum = 0;
  for(int i=1; i<=k; i++){
    dd[i] = d[i] / m;
    if(dd[i] < 2) continue;
    if(dd[i] % 2)
      odd++;
    else if(dd[i] > 2)
      even++;
    sum += dd[i];
  }
  if(n % 2 == 0 || (odd > 0 || even > 0)){
    if(n % 2 == 1 && odd % 2 == 0) sum--;
    if(sum >= n){
      puts("Yes");
      return;
    }
  }
  
  puts("No");
}

int main(){
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
