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

long long fib[N];

void solve(){
  int k; scanf("%d", &k);
  vector<int> d(k), p(k, 0);
  multiset<pii> setik;
  long long sum = 0;
  for(int i=0; i<k; i++){
    scanf("%d", &d[i]);
    setik.insert({d[i], -1});
    sum += d[i];
  }
  sort(all(d));
  reverse(all(d));
  int m = -1;
  for(int i=0; i<N-1; i++){
    if(sum < fib[i]) break;
    m = i;
    sum -= fib[i];
  }
  if(sum > 0){
    puts("NO");
    return;
  }
  for(int i=m; i>=0; i--){
    auto a = *setik.rbegin();
    setik.erase(setik.find(a));
    if(a.ss != i+1){
      if(a.ff < fib[i]){
        puts("NO");
        return;
      }
      a.ff -= fib[i];
      a.ss = i;
      setik.insert(a);
    }
    else{
      if(k == 1){
        puts("NO");
        return;
      }
      auto b = *setik.rbegin();
      setik.erase(setik.find(b));
      if(b.ff < fib[i]){
        puts("NO");
        return;
      }
      b.ff -= fib[i];
      b.ss = i;
      setik.insert(b);
      setik.insert(a);
    }
  }
  puts("YES");
}

int main(){
  fib[0] = 1, fib[1] = 1;
  for(int i=2; i<N-1; i++){
    fib[i] = fib[i-1] + fib[i-2];
    if(fib[i] > (long long)1e12)
      break;
  }
  int testcase = 1;
  scanf("%d", &testcase);
  while(testcase--){
    solve();
  }
  return 0;
}
