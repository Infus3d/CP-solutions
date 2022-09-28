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
  int n; scanf("%d", &n);
  long long x; scanf("%lld", &x);
  queue<long long> Q;
  Q.push(x);
  map<long long, int> dist;
  dist[x] = 0;
  while(!Q.empty()){
    long long cur = Q.front();
    Q.pop();
    long long a = cur;
    vector<int> digits;
    while(a > 0){
      digits.push_back(a % 10);
      a /= 10;
    }
    if(sz(digits) == n){
      printf("%d\n", dist[cur]);
      return;
    }
    for(int dig : digits){
      if(dist.find(cur*dig) == dist.end() || dist[cur*dig] > dist[cur]+1){
        dist[cur*dig] = dist[cur]+1;
        Q.push(cur*dig);
      }
    }
  }
  puts("-1");
}

int main(){
  int testcase = 1;
  //~ scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
