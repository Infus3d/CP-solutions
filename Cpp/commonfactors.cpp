// try to find "the most composite number" under n
// i.e. multiply the most number of prime numbers until you reach n
// which greedily implies that you need to start with 2 and
// and proceed 2*3*5*7*...*p_k <= n
// There is a nice proof of this approach that uses euler's totient function

#include "bits/stdc++.h"

#define ff first
#define ss second
#define pb push_back
#define ll long long
#define db puts("*****")
#define sz(x) int(x.size())
#define pii pair <int , int>
#define mid(x , y) ((x+y)>>1)
#define all(x)  x.begin(),x.end()
#define y1 your_name_engraved_herein

using namespace std;

const int N = 2e5+2;
const int K = 1e3+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0;}
template<class T> bool umax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}

vector<int> primes;

void solve(){
  ll n; scanf("%lld", &n);
  for(int i=2; i<=500; i++){
    bool pr = true;
    for(int j=2; j*j<=i; j++)
      if(i % j == 0)
        pr = false;
    if(pr == true)
      primes.pb(i);
  }
  
  int cnt = 0;
  ll m = 1;
  for(int i : primes){
    ++cnt;
    if(n / i < m) break;
    m *= i;
  }
  
  ll q = 0; cnt--;
  for(int mask=1; mask<(1<<cnt); mask++){
    int count = __builtin_popcount(mask);
    ll div = 1;
    for(int j=0; j<cnt; j++)
      if((1<<j)&mask)
        div *= primes[j];
    
    if(count % 2 == 1)
      q += m / div;
    else
      q -= m / div;
  }
  
  ll gicidi = __gcd(q, m);
  printf("%lld/%lld\n", q/gicidi, m/gicidi);
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
