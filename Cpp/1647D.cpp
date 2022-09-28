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
const int K = 2e7+2;
const int MOD = 998244353;

template<class T> bool umin(T& a, T b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> bool umax(T& a, T b) { if(a < b){ a = b; return 1; } return 0; }

bool notprime[K];

bool isPrime(int x){
  if(x < K-1) return !notprime[x];
  for(int i=2; i*i<=x; i++){
    if(x % i == 0)
      return false;
  }
  return true;
}

vector<pii> prime_factorization(int x){
  vector<pii> res;
  int div = 2;
  if(isPrime(x)){
    res.push_back({x, 1});
    return res;
  }
  while(x > 1){
    if(x % div == 0){
      res.push_back({div, 0});
      while(x % div == 0){
        res.back().ss++;
        x /= div;
      }
      if(isPrime(x)){
        res.push_back({x, 1});
        break;
      }
    }
    div++;
  }
  return res;
}

void solve(){
  int x, d;
  scanf("%d%d", &x, &d);
  vector<pii> xprime = prime_factorization(x);
  vector<pii> dprime = prime_factorization(d);
  //~ printf("x->%d factorization:\n", x);
  //~ for(pii i : xprime) printf("%d %d\n", i.ff, i.ss);
  //~ printf("d->%d factorization:\n", d);
  //~ for(pii i : dprime) printf("%d %d\n", i.ff, i.ss);
  int mini = (int)1e9, sumx = 0, sumd = 0;
  for(pii i : xprime) sumx += i.ss;
  for(pii i : dprime) sumd += i.ss;
  for(pii i : dprime){
    for(pii j : xprime){
      if(i.ff == j.ff){
        mini = min(mini, j.ss / i.ss);
      }
    }
  }
  //~ printf("mini -> %d\n", mini);
  if(mini < 2)
    puts("NO");
  else if(mini == 2 && (sumx - (mini * sumd)) < 2)
    puts("NO");
  else if(mini > 2 && (sumx - (mini * sumd)) < 2 && sz(dprime) == 1){
    int rem = -1;
    for(pii i : xprime){
      if(i.ff == dprime.back().ff){
        rem = i.ss - ((mini-1) * dprime.back().ss);
      }
    }
    assert(rem != -1);
    rem = (rem + (mini-2)) / (mini-1);
    printf("%s\n", rem < dprime.back().ss ? "YES" : "NO");
  }
  else puts("YES");
}

int main(){
  notprime[0] = notprime[1] = 1;
  for(int i=2; i<K-1; i++){
    if(notprime[i]) continue;
    for(int j=i+i; j<K-1; j+=i)
      notprime[j] = true;
  }
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
