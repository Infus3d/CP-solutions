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

int P[(int)1e6+2], vis[(int)1e6];
vector<int> primes;
int dp[21];
map<vector<char>, int> mk;

vector<int> prime_factorization(int val){
  vector<int> ret;
  for(int i : primes){
    if(val == 1) break;
    while(val % i == 0)
      ret.pb(i), val /= i;
  }
  if(val > 1) ret.pb(val);
  vector<int> r;
  for(int i : ret){
    while(i > 0){
      r.pb((i%10));
      i /= 10;
    }
  }
  return r;
}

int add(int x, int y){
  return (x + y) % MOD;
}

void sieve(){
  for(int i=2; i<=(int)1e6; i++)
    if(!P[i]){
      for(int j=i+i; j<=(int)1e6; j+=i)
        P[j] = i;
      primes.pb(i);
    }
}

int solve(int n){
  if(vis[n] != 0) return vis[n]; 
  vector<int> res = prime_factorization(n);
  sort(all(res));
  assert(sz(res) <= 20);
  int m = sz(res), ans = 0;
  
  do{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=1; i<=m; i++){
      if(res[i-1] != 0)
        dp[i] = add(dp[i], dp[i-1]);
      if(i > 1 && (res[i-2] != 0 && ((res[i-2])*10 + (res[i-1])) <= 26))
        dp[i] = add(dp[i], dp[i-2]);
    }
    ans = add(ans, dp[m]);
  }
  while(next_permutation(all(res)));
  return vis[n] = ans;
}

int main(){
  sieve();
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(cin >> testcase){
    printf("%d\n", solve(testcase));
  }
  
  return 0;
}
/*
 * max op: 1544249, the num: 930240
*/
